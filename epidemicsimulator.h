#ifndef EPIDEMICSIMULATOR_H
#define EPIDEMICSIMULATOR_H

#include <QMainWindow>

namespace Ui {
class EpidemicSimulator;
}

class EpidemicSimulator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit EpidemicSimulator(QWidget *parent = 0);
    ~EpidemicSimulator();
    
private:
    Ui::EpidemicSimulator *ui;
};

#endif // EPIDEMICSIMULATOR_H
