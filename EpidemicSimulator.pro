#-------------------------------------------------
#
# Project created by QtCreator 2012-04-27T13:37:56
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = EpidemicSimulator
TEMPLATE = app
CONFIG += qwt

SOURCES += main.cpp\
        epidemicsimulator.cpp \
    grid.cpp \
    square.cpp \
    resident.cpp \
    simulator.cpp

HEADERS  += epidemicsimulator.h \
    grid.h \
    square.h \
    resident.h \
    simulator.h

FORMS    += epidemicsimulator.ui

INCLUDEPATH += /usr/local/qwt-6.1.0/lib/qwt.framework/Versions/6/Headers

//QMAKE_LFLAGS += -F/usr/local/qwt-6.0.1/lib/

LIBS += -framework qwt

//OTHER_FILES +=
