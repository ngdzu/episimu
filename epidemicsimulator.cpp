#include "epidemicsimulator.h"
#include "ui_epidemicsimulator.h"

EpidemicSimulator::EpidemicSimulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EpidemicSimulator)
{
    ui->setupUi(this);
}

EpidemicSimulator::~EpidemicSimulator()
{
    delete ui;
}
