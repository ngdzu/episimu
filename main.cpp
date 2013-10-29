#include <QtGui/QApplication>
#include "epidemicsimulator.h"
#include <time.h>

int main(int argc, char *argv[])
{

    srand(time(NULL));
    QApplication a(argc, argv);
    EpidemicSimulator w;
    w.show();

    return a.exec();
}
