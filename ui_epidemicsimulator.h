/********************************************************************************
** Form generated from reading UI file 'epidemicsimulator.ui'
**
** Created: Fri May 18 01:39:52 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EPIDEMICSIMULATOR_H
#define UI_EPIDEMICSIMULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <grid.h>

QT_BEGIN_NAMESPACE

class Ui_EpidemicSimulator
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QSpinBox *spinBox;
    QSpinBox *incubation_Period;
    QLabel *label_6;
    QSpinBox *contagiousPeriodBox;
    QLabel *label_7;
    QPushButton *graph_Simulation;
    QSpinBox *init_Population;
    grid *widget;
    QLabel *label_5;
    QLabel *label_2;
    QDoubleSpinBox *infection_Rate;
    QLabel *label_3;
    QLabel *label;
    QPushButton *stop_Simulation;
    QDoubleSpinBox *init_Infected;
    QLabel *label_8;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber;
    QLabel *label_9;
    QPushButton *dislay_Legend;
    QSpacerItem *horizontalSpacer;
    QDoubleSpinBox *DeathRate;
    QLabel *label_4;
    QRadioButton *immunityYes;
    QRadioButton *ImmunityNo;
    QGroupBox *city_Specs;
    QRadioButton *is_Dense;
    QRadioButton *is_Sparse;
    QPushButton *run_Simulation;
    QLabel *label_11;
    QSpinBox *spinBox_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;

    void setupUi(QMainWindow *EpidemicSimulator)
    {
        if (EpidemicSimulator->objectName().isEmpty())
            EpidemicSimulator->setObjectName(QString::fromUtf8("EpidemicSimulator"));
        EpidemicSimulator->resize(887, 796);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EpidemicSimulator->sizePolicy().hasHeightForWidth());
        EpidemicSimulator->setSizePolicy(sizePolicy);
        EpidemicSimulator->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(EpidemicSimulator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_10, 12, 0, 1, 1);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(101, 27));
        spinBox->setMinimum(1);
        spinBox->setMaximum(200);
        spinBox->setValue(50);

        gridLayout->addWidget(spinBox, 13, 0, 1, 1);

        incubation_Period = new QSpinBox(centralWidget);
        incubation_Period->setObjectName(QString::fromUtf8("incubation_Period"));
        incubation_Period->setMinimumSize(QSize(101, 27));
        incubation_Period->setMaximumSize(QSize(101, 27));
        incubation_Period->setMinimum(0);
        incubation_Period->setMaximum(14);
        incubation_Period->setValue(1);

        gridLayout->addWidget(incubation_Period, 9, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_6, 10, 0, 1, 1);

        contagiousPeriodBox = new QSpinBox(centralWidget);
        contagiousPeriodBox->setObjectName(QString::fromUtf8("contagiousPeriodBox"));
        contagiousPeriodBox->setMaximumSize(QSize(101, 27));
        contagiousPeriodBox->setMaximum(60);
        contagiousPeriodBox->setValue(10);

        gridLayout->addWidget(contagiousPeriodBox, 11, 0, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_7, 16, 0, 1, 1);

        graph_Simulation = new QPushButton(centralWidget);
        graph_Simulation->setObjectName(QString::fromUtf8("graph_Simulation"));
        graph_Simulation->setMinimumSize(QSize(97, 27));
        graph_Simulation->setMaximumSize(QSize(97, 27));

        gridLayout->addWidget(graph_Simulation, 22, 3, 1, 1);

        init_Population = new QSpinBox(centralWidget);
        init_Population->setObjectName(QString::fromUtf8("init_Population"));
        init_Population->setMinimumSize(QSize(101, 27));
        init_Population->setMaximumSize(QSize(101, 27));
        init_Population->setMinimum(2);
        init_Population->setMaximum(5000);
        init_Population->setValue(50);

        gridLayout->addWidget(init_Population, 1, 0, 1, 1);

        widget = new grid(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(561, 520));
        widget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(widget, 0, 1, 22, 5);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        infection_Rate = new QDoubleSpinBox(centralWidget);
        infection_Rate->setObjectName(QString::fromUtf8("infection_Rate"));
        infection_Rate->setMinimumSize(QSize(101, 27));
        infection_Rate->setMaximumSize(QSize(101, 27));
        infection_Rate->setDecimals(2);
        infection_Rate->setMaximum(100);
        infection_Rate->setValue(50);

        gridLayout->addWidget(infection_Rate, 5, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(101, 20));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        stop_Simulation = new QPushButton(centralWidget);
        stop_Simulation->setObjectName(QString::fromUtf8("stop_Simulation"));
        stop_Simulation->setMinimumSize(QSize(97, 27));
        stop_Simulation->setMaximumSize(QSize(97, 27));

        gridLayout->addWidget(stop_Simulation, 22, 2, 1, 1);

        init_Infected = new QDoubleSpinBox(centralWidget);
        init_Infected->setObjectName(QString::fromUtf8("init_Infected"));
        init_Infected->setMinimumSize(QSize(101, 27));
        init_Infected->setMaximumSize(QSize(101, 27));
        init_Infected->setDecimals(2);
        init_Infected->setMinimum(0.01);
        init_Infected->setMaximum(99.9);
        init_Infected->setValue(10);

        gridLayout->addWidget(init_Infected, 3, 0, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_8, 20, 0, 1, 1);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        sizePolicy2.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy2);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(5);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 21, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMaximumSize(QSize(55, 27));
        lcdNumber->setNumDigits(4);

        horizontalLayout->addWidget(lcdNumber);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(label_9);


        gridLayout->addLayout(horizontalLayout, 22, 0, 1, 1);

        dislay_Legend = new QPushButton(centralWidget);
        dislay_Legend->setObjectName(QString::fromUtf8("dislay_Legend"));
        dislay_Legend->setMinimumSize(QSize(97, 27));
        dislay_Legend->setMaximumSize(QSize(97, 27));

        gridLayout->addWidget(dislay_Legend, 22, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(212, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 22, 5, 1, 1);

        DeathRate = new QDoubleSpinBox(centralWidget);
        DeathRate->setObjectName(QString::fromUtf8("DeathRate"));
        DeathRate->setMinimumSize(QSize(101, 27));
        DeathRate->setMaximumSize(QSize(101, 27));
        DeathRate->setMinimum(0);
        DeathRate->setMaximum(100);
        DeathRate->setValue(80);

        gridLayout->addWidget(DeathRate, 7, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        immunityYes = new QRadioButton(centralWidget);
        immunityYes->setObjectName(QString::fromUtf8("immunityYes"));
        sizePolicy2.setHeightForWidth(immunityYes->sizePolicy().hasHeightForWidth());
        immunityYes->setSizePolicy(sizePolicy2);
        immunityYes->setMaximumSize(QSize(16777215, 20));
        immunityYes->setChecked(true);

        gridLayout->addWidget(immunityYes, 17, 0, 1, 1);

        ImmunityNo = new QRadioButton(centralWidget);
        ImmunityNo->setObjectName(QString::fromUtf8("ImmunityNo"));
        sizePolicy2.setHeightForWidth(ImmunityNo->sizePolicy().hasHeightForWidth());
        ImmunityNo->setSizePolicy(sizePolicy2);
        ImmunityNo->setMaximumSize(QSize(16777215, 20));
        ImmunityNo->setChecked(false);

        gridLayout->addWidget(ImmunityNo, 18, 0, 1, 1);

        city_Specs = new QGroupBox(centralWidget);
        city_Specs->setObjectName(QString::fromUtf8("city_Specs"));
        city_Specs->setMinimumSize(QSize(120, 81));
        city_Specs->setMaximumSize(QSize(120, 81));
        is_Dense = new QRadioButton(city_Specs);
        is_Dense->setObjectName(QString::fromUtf8("is_Dense"));
        is_Dense->setGeometry(QRect(0, 30, 116, 21));
        is_Dense->setChecked(true);
        is_Sparse = new QRadioButton(city_Specs);
        is_Sparse->setObjectName(QString::fromUtf8("is_Sparse"));
        is_Sparse->setGeometry(QRect(0, 50, 116, 22));

        gridLayout->addWidget(city_Specs, 19, 0, 1, 1);

        run_Simulation = new QPushButton(centralWidget);
        run_Simulation->setObjectName(QString::fromUtf8("run_Simulation"));
        run_Simulation->setMinimumSize(QSize(97, 27));
        run_Simulation->setMaximumSize(QSize(97, 27));

        gridLayout->addWidget(run_Simulation, 22, 1, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_11, 14, 0, 1, 1);

        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximumSize(QSize(101, 27));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(100);
        spinBox_2->setValue(70);

        gridLayout->addWidget(spinBox_2, 15, 0, 1, 1);

        EpidemicSimulator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EpidemicSimulator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 887, 25));
        EpidemicSimulator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EpidemicSimulator);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        EpidemicSimulator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EpidemicSimulator);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EpidemicSimulator->setStatusBar(statusBar);
        toolBar = new QToolBar(EpidemicSimulator);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        EpidemicSimulator->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(EpidemicSimulator);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        EpidemicSimulator->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(EpidemicSimulator);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        EpidemicSimulator->addToolBar(Qt::TopToolBarArea, toolBar_3);
        toolBar_4 = new QToolBar(EpidemicSimulator);
        toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
        EpidemicSimulator->addToolBar(Qt::TopToolBarArea, toolBar_4);

        retranslateUi(EpidemicSimulator);
        QObject::connect(init_Population, SIGNAL(valueChanged(int)), widget, SLOT(readPopulation(int)));
        QObject::connect(infection_Rate, SIGNAL(valueChanged(double)), widget, SLOT(readInfectionRate(double)));
        QObject::connect(incubation_Period, SIGNAL(valueChanged(int)), widget, SLOT(readIncubationPeriod(int)));
        QObject::connect(init_Infected, SIGNAL(valueChanged(double)), widget, SLOT(readInitInfected(double)));
        QObject::connect(graph_Simulation, SIGNAL(clicked(bool)), widget, SLOT(displayGraph()));
        QObject::connect(dislay_Legend, SIGNAL(clicked()), widget, SLOT(displayLegend()));
        QObject::connect(DeathRate, SIGNAL(valueChanged(double)), widget, SLOT(readDeathRate(double)));
        QObject::connect(run_Simulation, SIGNAL(clicked()), widget, SLOT(runSimulation()));
        QObject::connect(stop_Simulation, SIGNAL(clicked()), widget, SLOT(stopSimulation()));
        QObject::connect(immunityYes, SIGNAL(clicked()), widget, SLOT(readHasImmune()));
        QObject::connect(ImmunityNo, SIGNAL(clicked()), widget, SLOT(readDoesNotHaveImmune()));
        QObject::connect(is_Dense, SIGNAL(clicked()), widget, SLOT(readCityDense()));
        QObject::connect(is_Sparse, SIGNAL(clicked()), widget, SLOT(readCitySparse()));
        QObject::connect(contagiousPeriodBox, SIGNAL(valueChanged(int)), widget, SLOT(readContagiousPeriod(int)));
        QObject::connect(init_Infected, SIGNAL(valueChanged(double)), widget, SLOT(readInitInfected(double)));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), widget, SLOT(onSpeedChanged(int)));
        QObject::connect(widget, SIGNAL(numDaysChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), widget, SLOT(readBlocksPerDay(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), widget, SLOT(readPctOnStreet(int)));

        QMetaObject::connectSlotsByName(EpidemicSimulator);
    } // setupUi

    void retranslateUi(QMainWindow *EpidemicSimulator)
    {
        EpidemicSimulator->setWindowTitle(QApplication::translate("EpidemicSimulator", "EpidemicSimulator", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("EpidemicSimulator", "Travel distance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>The average number of blocks the residents travel per day</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        incubation_Period->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>The length of the incubation period (in days)</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("EpidemicSimulator", "Contagious period", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        contagiousPeriodBox->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>The length of the contagious period (in days)</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>Will the patient immune against the disease</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("EpidemicSimulator", "Immunity", 0, QApplication::UnicodeUTF8));
        graph_Simulation->setText(QApplication::translate("EpidemicSimulator", "Graph", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        init_Population->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>Totoal number of people.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("EpidemicSimulator", "Initial infected", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EpidemicSimulator", "Infection  rate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        infection_Rate->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>Pecent chance of being infected</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("EpidemicSimulator", "Death rate", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EpidemicSimulator", "Population", 0, QApplication::UnicodeUTF8));
        stop_Simulation->setText(QApplication::translate("EpidemicSimulator", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        init_Infected->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>Percentage of the population who get infected when the program starts</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("EpidemicSimulator", "Speed", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("EpidemicSimulator", "days", 0, QApplication::UnicodeUTF8));
        dislay_Legend->setText(QApplication::translate("EpidemicSimulator", "Legend", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        DeathRate->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>Percent chance of dying after the contagious period</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("EpidemicSimulator", "Incubation period", 0, QApplication::UnicodeUTF8));
        immunityYes->setText(QApplication::translate("EpidemicSimulator", "Yes", 0, QApplication::UnicodeUTF8));
        ImmunityNo->setText(QApplication::translate("EpidemicSimulator", "No", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        city_Specs->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>Population density</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        city_Specs->setTitle(QApplication::translate("EpidemicSimulator", "City Specs", 0, QApplication::UnicodeUTF8));
        is_Dense->setText(QApplication::translate("EpidemicSimulator", "Dense", 0, QApplication::UnicodeUTF8));
        is_Sparse->setText(QApplication::translate("EpidemicSimulator", "Sparse", 0, QApplication::UnicodeUTF8));
        run_Simulation->setText(QApplication::translate("EpidemicSimulator", "Run", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("EpidemicSimulator", "Percent traveling", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_2->setToolTip(QApplication::translate("EpidemicSimulator", "<html><head/><body><p>The percentage of time the residents spend travelling</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("EpidemicSimulator", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("EpidemicSimulator", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("EpidemicSimulator", "toolBar_3", 0, QApplication::UnicodeUTF8));
        toolBar_4->setWindowTitle(QApplication::translate("EpidemicSimulator", "toolBar_4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EpidemicSimulator: public Ui_EpidemicSimulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EPIDEMICSIMULATOR_H
