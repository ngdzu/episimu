#ifndef GRID_H
#define GRID_H

#include <QGLWidget>
#include "simulator.h"

using namespace std;

typedef struct{
    int a,b;
    float x,y;
}residentInfo;

class grid : public QGLWidget
{
    Q_OBJECT
public:
    explicit grid(QWidget *parent = 0);


protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    Simulator *sim;
    residentInfo *residentLocation; /*hold coordinate of the residents*/

int sh, sw; /* height and width of the drawing erea*/


int population;
double initialInfected;
double infectionRate;
double deathRate;
bool hasImmunity;
bool dense;
int incubationPeriod;
int contagiousPeriod;

int speed;

int numDays;

int blocksPerDay;
int pctOnStreet;

bool isRunning;
bool runButtonAlreadyClicked;
bool stopButtonAlreadyClicked;


    void drawNewPosition(int squareSide);
    void drawMovement(int squareSide);
    
signals:
    void numDaysChanged(int n);
    
public slots:
    void readPopulation(int population);
    void readInfectionRate(double percentage);
    void readDeathRate(double percent);
    void readIncubationPeriod(int incubation);
    void readContagiousPeriod(int contagPer);
    void readInitInfected(double initialPercentInfected);
    void readHasImmune();
    void readDoesNotHaveImmune();
    void readCityDense();
    void readCitySparse();
    void readBlocksPerDay(int blocksPerDay);
    void readPctOnStreet(int pctOnStreet);
    void runSimulation();
    void stopSimulation();
    void displayLegend();
    void displayGraph();
    void onSpeedChanged(int value);

};

#endif // GRID_H
