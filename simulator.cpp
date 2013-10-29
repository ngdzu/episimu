/*
 *  simulator.cpp
 *  Epidemic
 *
 *  Created by AKOMN on 3/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "simulator.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>


#include <iostream>
using namespace std;


void wait(double seconds);

Simulator::Simulator(
        int populationSize,
        bool dense,
        double percentStartedWithDisease,
        double percentGetInfected,
        double percentDead,
        bool immuned,
        int contagiousTime,
        int incubatingTime,
        int blocksPerDay,
        int pctOnStreet

        )
{
    this->populationSize = populationSize;
    this->dense = dense;
    this->percentStartedWithDisease = percentStartedWithDisease;
    this->percentGetInfected = percentGetInfected;
    this->percentDead = percentDead;
    this->hasImmunity = immuned;
    this->incubatingTime = incubatingTime * blocksPerDay;
    this->contagiousTime = contagiousTime * blocksPerDay;
    this->blocksPerDay = blocksPerDay;
    this->pctOnStreet = pctOnStreet;
    
    this->numDead = 0;
    this->numInstance = 0;
    this->numCase = 0;
    
    infectedResidents = new bool[populationSize];
    for (int i=0; i<populationSize; i++) {
        infectedResidents[i] = false;
    }
    
    initGrid();
    initPopulation();
    
//    /*-------DEBUG------*/
//    cout << "num infected initially: " << getNumInfected() << endl;
}


void Simulator::initGrid(){
    int numberOfHouses;
    
    if(dense){
        numberOfHouses = populationSize * 100 / 80; /*80% housed are occupied*/
    }
    else{
        numberOfHouses = populationSize * 100 / 40; /*40% */
    }
    
    /*the grid always is a square (rectangle with equal sides)*/
    side = ((int)sqrt(numberOfHouses) + 1) * 2 + 1;
    
    /*create 2-dimentional array of Squares*/
    grid = new Square* [side];
    for(int i=0; i< side ; i++){
        grid[i] = new Square[side];
    }
    
    /*connect the Squares and decide which ones are houses*/
    for(int i=0; i<side ; i++){
        for(int j=0; j<side; j++){
            Square *up = &grid[i-1][j];
            Square *right = &grid[i][j+1];
            Square *bottom = &grid[i+1][j];
            Square *left = &grid[i][j-1];
            
            grid[i][j].setLoc(j,i);
            
            if(i==0){
                if(j==0){ /*top left Square*/
                    grid[i][j].setNext(NULL, right, bottom, NULL);
                }
                else if(j == side-1){ /*top right Square*/
                    grid[i][j].setNext(NULL, NULL, bottom, left);
                }
                else{ /*the rest of other squares on the top row*/
                    grid[i][j].setNext(NULL, right, bottom, left);
                }
                grid[i][j].setHouse(false);
            }
            
            else if(i == side - 1){
                
                if(j==0){ /*bottom left Square*/
                    grid[i][j].setNext(up, right, NULL, NULL);
                }
                else if(j == side-1){ /*bottom right Square*/
                    grid[i][j].setNext(up, NULL, NULL, left);
                }
                else{ /*the rest of the Squares on the bottom row*/
                    grid[i][j].setNext(up, right, NULL, left);
                }
                
                grid[i][j].setHouse(false);
            }
            
            else{
                if(j==0){ /*Squares on the left-most column*/
                    grid[i][j].setNext(up, right, bottom, NULL);
                }
                else if(j == side-1){ /*Squares on the right-most column*/
                    grid[i][j].setNext(up, NULL, bottom, left);
                }
                else{ /*all the Squares not on the edges of the grid*/
                    grid[i][j].setNext(up, right, bottom, left);
                }
                
                /*assign houses*/
                if(i % 2 == 1){ /*there will be houses on this row*/
                    if(j % 2 == 1){
                        grid[i][j].setHouse(true);
                        availableHouse.push_back(&grid[i][j]);
                    }
                    else{
                        grid[i][j].setHouse(false);
                    }
                }
                else{
                    grid[i][j].setHouse(false);
                }
                
            }
        }
    }
    
}


void Simulator::initPopulation(){
    resident = new Resident[populationSize];
    
//    srand(time(NULL));
    for(int i=0; i<populationSize ; i++){
        int rd = rand() % availableHouse.size();
        
        /*assign house to this resident*/
        resident[i].setHomeLoc(availableHouse[rd]);
        resident[i].setLoc(availableHouse[rd]);
        availableHouse.erase(availableHouse.begin() + rd); /*remove house occupied*/
        
        /*set up*/
        resident[i].setUp(percentGetInfected, percentDead,hasImmunity, contagiousTime, incubatingTime, blocksPerDay, pctOnStreet);
        
        /*set initial health condition*/
        if(rand() % (100 * 1000) < percentStartedWithDisease * 1000){/*this person is infected*/
            infectedResidents[i] = true; 
            resident[i].initCondition(incubating);
        }
        else{
            resident[i].setCondition(healthy);
        }
        
        
        
    }
    
}

Resident *Simulator::getResident(){
    return resident;
}

int Simulator::getSide(){
    return side;
}

int Simulator::getNumDead(){
    int count = 0;
    for(int i=0 ; i<populationSize ; i++){
        if(resident[i].getCondition() == dead)
            count++;
    }
    return count;
}

int Simulator::getNumInfected(){
    int count = 0;
    for (int i=0; i<populationSize; i++) {
        if (resident[i].getCondition() == incubating 
            || resident[i].getCondition() == contagious) 
        {
            count++;
        }
    }
    return count;
}

int Simulator::getNumCase(){
    return numCase;
}

int Simulator::getTimeRun(){
    return numInstance /blocksPerDay;
}

int Simulator::getNumInstance(){
    return numInstance;
}

void Simulator::run(){
    
    while(true){
        
        
        /*DEBUG*/
//        int numdead = getNumDead();
//        int numinfected = getNumInfected();
//        cout << "numinfected: " << numinfected << endl;
        
        /*condition to terminate the program*/
//        if(getNumDead() == populationSize) break; /*all dead*/
        if(getNumInfected() == 0) break; /*all cured*/

        
        /*hit stop button (to be implemented)*/
        /*...*/
        
        numInstance++; /*the number of instances*/
        
        
//        /***************************DEBUG*************************/
//        cout << numInstance << endl;
        
        /*reset the state of all squares*/
        for(int i=0 ; i<side ; i++){
            for(int j=0 ; i<side ; i++){
                grid[i][j].setInfective(false);
            }
            
        }
        
        /*move the resident*/
        for(int i=0 ; i<populationSize ; i++){
            resident[i].move(); /*as they move, the square's state is updated*/
        }
        
        /*update health condition*/
        for(int i=0 ; i<populationSize ; i++){
            state previousCondition = resident[i].getCondition();
            
            /*update health condition*/
            resident[i].updateHealthCondition();
            
            state currentHealthCondition = resident[i].getCondition();
            
            if (previousCondition == healthy && currentHealthCondition == incubating) {
                infectedResidents[i] = true;
                numCase++;
            }
            if (previousCondition == contagious) {
                if (currentHealthCondition==healthy 
                    || currentHealthCondition==immuned 
                    || currentHealthCondition== dead) 
                {   
                    infectedResidents[i] = false;
                }
            }
        }
        
    }
    
}

bool Simulator::runOneInstance(){
    if(getNumInfected() == 0) /*all cured or all dead*/
        return false;

    /*record points to plot on the graphs*/
    if(numInstance % blocksPerDay == 0){

        infectionPlot.push_back(getNumInfected());

        deathPlot.push_back(getNumDead());

        timesTrasmittedPlot.push_back(getNumCase());
    }

    numInstance++; /*the number of instances*/


    /*reset state of all square*/
    for(int i=0 ; i<side ; i++){
        for(int j=0 ; j<side ; j++){
            grid[i][j].setInfective(false);
        }
    }

    /*move the resident*/
    for(int i=0 ; i<populationSize ; i++){
        resident[i].move(); /*as they move, the square's state is updated*/
    }

    /*update health condition*/
    for(int i=0 ; i<populationSize ; i++){
        state previousCondition = resident[i].getCondition();

        /*update health condition*/
        resident[i].updateHealthCondition();

        state currentHealthCondition = resident[i].getCondition();

        if (previousCondition == healthy && currentHealthCondition == incubating) {
            infectedResidents[i] = true;
            numCase++;
        }
        if (previousCondition == contagious) {
            if (currentHealthCondition==healthy
                || currentHealthCondition==immuned
                || currentHealthCondition== dead)
            {
                infectedResidents[i] = false;
            }
        }
    }



    return true;

}

void wait(double seconds){
    clock_t endwait;
    endwait = clock() + (int)(seconds * CLOCKS_PER_SEC);
    while(clock() < endwait){}
}


Simulator::~Simulator(){
    /*destroy the grid and population*/
    for(int i=side-1; i>=0; i--){
        delete []grid[i];
    }

    delete []resident;

    infectionPlot.clear();
    deathPlot.clear();
    timesTrasmittedPlot.clear();

}
