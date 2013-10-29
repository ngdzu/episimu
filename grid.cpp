#include "grid.h"
#include <iostream>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include<qwt_plot_grid.h>
#include <QMessageBox>
#include <QTimer>
#include <time.h>

#define FREQ 10

grid::grid(QWidget *parent) :
    QGLWidget(parent)
{
    isRunning = false;
    runButtonAlreadyClicked = false;
    stopButtonAlreadyClicked = false;
    population = 50;
    initialInfected = 10;
    infectionRate = 20;
    deathRate = 80;
    incubationPeriod = 2;
    contagiousPeriod = 10;
    hasImmunity = true;
    dense = true;
    speed = 50;
    blocksPerDay = 50;
    pctOnStreet = 70;

}


void grid::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    //        glEnable(GL_DEPTH_TEST); /*added*/

}
void grid::resizeGL(int width, int height){
    /*  double ratio = width/height;
    double newWidth, newHeight;
        glViewport(0,0,width, height);//width height
        glOrtho(0.0, width,0.0, height, 0.0, 1.0);//width height
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();*/
    sw = width;
    sh = height;

}

int tickCount = 0;

void grid::paintGL(){

    //setting up the screen
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glDisable(GL_DEPTH_TEST);
    glLoadIdentity();
    // checking the size of the screen
    /*  GLfloat m[16];
    glGetFloatv (GL_MODELVIEW_MATRIX, m);
    for(int d =0; d<16; d++)
        std::cout<< "dimesions: "<< m[d]<<endl;*/

    glViewport(0,0,sw, sh);//width height
    glOrtho(0.0, sw,0.0, sh, 0.0, 1.0);//width height
    //  std::cout<<"screen width: \n"<<sw;
    //  std::cout<<"screen height: \n"<<sh;
    if(isRunning){
        // drawing a Grid
        int side = sim->getSide();
        int minSize = (sw < sh)?sw:sh;
        int squareSide = minSize / side;


        /*draw the grid*/
        for(int i=squareSide ; i<minSize - squareSide ; i= i + 2* squareSide){
            for(int j=squareSide ; j<minSize -squareSide; j= j+ 2* squareSide){
                glColor3f(0.0f, 0.8f, 1.0f);
                glBegin(GL_QUADS);
                glVertex3f(i, j, 0.0f);
                glVertex3f(i+squareSide, j, 0.0f);
                glVertex3f(i+squareSide, j+squareSide, 0.0f);
                glVertex3f(i, j+squareSide, 0.0f);
                glEnd();
            }
        }

        if(tickCount++ %speed == 0){

            tickCount = 1;
            /*if successfully run one instance, draw the animation*/

            /*display the # of days on the LCD*/
            if(sim->getNumInstance() / blocksPerDay ){
                numDays = sim->getNumInstance() / blocksPerDay;
                emit numDaysChanged(numDays);
            }

            if(sim->runOneInstance()){
                drawNewPosition(squareSide);
            }
            else{
                stopSimulation(); /*stop the simulation*/
                return;
            }
        }
        else{
            drawMovement(squareSide);
        }

    }

}

void grid::drawMovement(int squareSide){
    Resident *currentResident = sim->getResident();
    for(int i=0; i< population; i++){

        if(currentResident[i].getCondition() != dead){
            /*set color*/
            if(currentResident[i].getCondition() == incubating) /*dangerous! access directly the population from the Simulator class*/
                glColor3f(1.0f, 1.0f, 0.0f); /*yellow*/
            else if(currentResident[i].getCondition() == immuned)
                glColor3f(0.0f, 1.0f, 0.0f); /*green*/
            else if(currentResident[i].getCondition() == healthy){
                glColor3f(1.0f, 1.0f, 1.0f); /*white*/
            }
            else if (currentResident[i].getCondition() == contagious)
                glColor3f(1.0f, 0.0f, 0.0f); /*red*/

        float x, y;
        float step = 1.0/speed *squareSide;

        int direction = currentResident[i].getDirectionOfMoving();
        switch(direction){
        case 0: residentLocation[i].y -= step; break;
        case 1: residentLocation[i].x += step; break;
        case 2: residentLocation[i].y += step; break;
        case 3: residentLocation[i].x -= step; break;
        default: break;

        }


        x = residentLocation[i].x;
        y = residentLocation[i].y;

        //        cout << "resident " << i << ": "<< currentResident[i].getLoc()->getX() << ", " << currentResident[i].getLoc()->getY() << endl;


        glPointSize(3.0); // 3 pixel dot!
        glBegin(GL_POINTS); // render with points

        glVertex2i(x, y); //display a point

        glEnd();
        }
    }

}



void grid::drawNewPosition(int squareSide){

    Resident *currentResident = sim->getResident();
    for(int i=0; i< population; i++){

        if(currentResident[i].getCondition() != dead){
            /*set color*/
            if(currentResident[i].getCondition() == incubating) /*dangerous! access directly the population from the Simulator class*/
                glColor3f(1.0f, 1.0f, 0.0f); /*yellow*/
            else if(currentResident[i].getCondition() == immuned)
                glColor3f(0.0f, 1.0f, 0.0f); /*green*/
            else if(currentResident[i].getCondition() == healthy){
                glColor3f(1.0f, 1.0f, 1.0f); /*white*/
            }
            else if (currentResident[i].getCondition() == contagious)
                glColor3f(1.0f, 0.0f, 0.0f); /*red*/
            //        else{
            //            glColor3f(1.0f, 0.0f, 3.0f); /*the rest */

            //        }

            //        cout << "print state: " << currentResident[i].getCondition() << endl;


            float x,y;

            x = residentLocation[i].x = squareSide * residentLocation[i].a / 10 + currentResident[i].getPreviousLoc()->getX() * squareSide;
            y = residentLocation[i].y = squareSide * residentLocation[i].b / 10 + currentResident[i].getPreviousLoc()->getY() * squareSide;

            //        cout << "resident " << i << ": "<< currentResident[i].getLoc()->getX() << ", " << currentResident[i].getLoc()->getY() << endl;

            glPointSize(3.0); // 5 pixel dot!
            glBegin(GL_POINTS); // render with points
            glVertex2i(x, y); //display a point
            glEnd();
        }

    }

}


void grid::runSimulation(){

    if(runButtonAlreadyClicked)
        return;



    /*create a simulator and run it*/
    sim = new Simulator(population, dense, initialInfected,
                        infectionRate, deathRate, hasImmunity,
                        contagiousPeriod, incubationPeriod, blocksPerDay, pctOnStreet  );

    /*get number of days*/
    numDays = sim->getNumInstance() / blocksPerDay;

    /*randomize the location of resident relative to a square*/
    residentLocation = new residentInfo[population];
    for(int i=0 ; i<population ; i++){
        residentLocation[i].a = rand() % 9 + 1;
        residentLocation[i].b = rand() % 9 + 1;
    }

//    std::cout<<"Run: "<<isRunning << endl;
    QTimer *timer = new QTimer;
    QObject:: connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1);

    isRunning = true;
    runButtonAlreadyClicked = true;
    stopButtonAlreadyClicked = false;



    //    /****************************DEBUG**********************************/
    //    std::cout<<"population: "<<population << endl;
    //    std::cout<<"Initial population infected: "<<initialInfected << endl;
    //    std::cout<<"Infection Rate: "<<infectionRate << endl;
    //    std::cout<<"Death rate: "<<deathRate << endl;
    //    std::cout<<"Incubation period: "<<incubationPeriod << endl;
    //    std::cout<<"contagious period: "<<contagiousPeriod << endl;
    //    std::cout<<"Is disease immune: "<<hasImmunity << endl;
    //    std::cout<<"Is disease immune: "<<hasImmunity << endl;
    //    cout << "dense: " << dense << endl;
    //    cout << "dense: " << dense << endl;
    //    /*********************END OF DEBUG**********************************/

}

void grid::stopSimulation(){
    if(stopButtonAlreadyClicked){
        return;
    }

    if(isRunning){
        isRunning = false;
        runButtonAlreadyClicked = false;
        stopButtonAlreadyClicked = true;

        displayGraph();
        emit numDaysChanged(0);

        //        std::cout<<"Stop: \n"<<isRunning;


        /*call deconstructor of Simulator class, which will destroy the grid and residents*/
        delete sim;

        /*delete resident location*/
        delete []residentLocation;
    }
}

void grid::readPopulation(int p){
    population = p;

    // std::cout<<"population: \n"<<population;
}
void grid::readInfectionRate(double per){
    infectionRate = per;
//    std::cout<<"Infection Rate: \n"<<infectionRate;

}

void grid::readDeathRate(double per){
    deathRate = per;
//    std::cout<<"Travel time: \n"<<deathRate;
}

void grid::readIncubationPeriod(int inc){
    incubationPeriod = inc;
//    std::cout<<"Incubation: \n"<<incubationPeriod;
}

void grid::readContagiousPeriod(int contagPer){
    contagiousPeriod = contagPer;
}

void grid::readInitInfected(double init){
    initialInfected = init;
//    std::cout<<"Initial population infected: \n"<<initialInfected;
}

void grid::readHasImmune(){
    hasImmunity = true;
//    std::cout<<"Is disease immune: \n"<<hasImmunity;
}

void grid::readDoesNotHaveImmune(){
    hasImmunity = false;
//    std::cout<<"Is disease immune: \n"<<hasImmunity;
}

void grid::readCityDense(){
    dense = true;
//    cout << "dense: " << dense << endl;
}
void grid::readCitySparse(){
    dense = false;
//    cout << "dense: " << dense << endl;
}

void grid::readBlocksPerDay(int blocksPerDay){
    this->blocksPerDay = blocksPerDay;
}

void grid::readPctOnStreet(int pctOnStreet){
    this->pctOnStreet = pctOnStreet;
}

void grid::onSpeedChanged(int value){
    speed = 101 - value; /* speed can't be zero, because rand() % speed later. */
}

void grid::displayLegend( ){
    QMessageBox msgBox;
    msgBox.setFixedSize(600, 600);
    msgBox.setText("Population: the population size. \n\
                   \n Travel time: the amount of time a resident spends outside his house.\n\
                   \n Incubation Period: the amount of time between getting infected and becoming contagious.\n\
                   \n Initial infected: the initial percentage of the population that is infected.\n\
                   \n Infection rate: the probability of getting infected after coming in contact with an infected individual.\n\
                   \n City Specs: determines if the city is densly populated or not.\n\
                   \n Disease Specs: determines if it is a deadly desease or an indiviual can grow immunity or if it is curable.\n\n");

                   msgBox.exec();
}
void grid::displayGraph(){
    QWidget *wid = new QWidget;
    wid->setFixedSize(800, 600);
    QwtPlot *myPlot = new QwtPlot(wid);
    myPlot->setMinimumSize(800, 600);
    myPlot->setTitle("Graph");
    myPlot->setCanvasBackground(QColor(Qt::white));
    myPlot->setAutoReplot(true);
    // axis
    myPlot->setAxisTitle(QwtPlot::xBottom, "Time (days)");
    myPlot->setAxisTitle(QwtPlot::yLeft, "Number of People");

    QPen pen;
    vector<int> tmp;
    double *x1, *y1;

    /*Infection graph*/

    tmp = *(sim->getInfectionPlot());

    x1 = new double[tmp.size()];
    y1 = new double[tmp.size()];

    for(int i=0 ; i<tmp.size() ; i++){
        x1[i] = i;
        y1[i] = tmp[i];
//        cout << x1[i] << ", " << y1[i] << ", " << endl;
    }


    QwtPlotCurve *curve1 = new QwtPlotCurve("Infection Curve");
    pen.setColor(Qt::red);
    pen.setWidth(2);
    curve1->setPen(pen);
    curve1->setRawSamples(x1, y1, tmp.size());
    curve1->attach(myPlot);

    //    delete []x1;
    //    delete []y1;



    /*death graph*/

    vector<int> tmp2;
    double *x2, *y2;

    tmp2 = *(sim->getDeathPlot());

    x2 = new double[tmp2.size()];
    y2 = new double[tmp2.size()];

    for(int i=0 ; i<tmp2.size() ; i++){
        x2[i] = i;
        y2[i] = tmp2[i];
//        cout << x2[i] << ", " << y2[i] << ", " << endl;
    }

    QwtPlotCurve *curve2 = new QwtPlotCurve("Infection Curve");
    pen.setColor(Qt::black);
    pen.setWidth(2);
    curve2->setPen(pen);
    curve2->setRawSamples(x2, y2, tmp2.size());
    curve2->attach(myPlot);


    /*draw number of infected graph*/
    vector<int> tmp3;
    double *x3, *y3;

    tmp3 = *(sim->getTimesTransmittedPlot());

    x3 = new double[tmp3.size()];
    y3 = new double[tmp3.size()];

    for(int i=0 ; i<tmp3.size() ; i++){
        x3[i] = i;
        y3[i] = tmp3[i];
//        cout << x3[i] << ", " << y3[i] << ", " << endl;
    }

    QwtPlotCurve *curve3 = new QwtPlotCurve("Infection Curve");
    pen.setColor(Qt::yellow);
    pen.setWidth(2);
    curve3->setPen(pen);
    curve3->setRawSamples(x3, y3, tmp3.size());
    curve3->attach(myPlot);

    myPlot->replot();
    wid->show();

    //    delete []x1;
    //    delete []y1;
}

