
/*
 *  resident.cpp
 *  Epidemic
 *
 *  Created by AKOMN on 3/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "resident.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

#define PCT_TRAVEL 60 /*60% of time on the street*/

Resident::Resident(){

    /*default constructor does nothing*/
}

Resident::Resident(state condition,
                   Square * const homeLocation,
                   Square *location,
                   float percentInfected,
                   float percentDead,
                   bool hsImmunity,
                   int count,
                   int contagCount,
                   int incubCount)
{
    con = condition;
    homeLoc = homeLocation;
    loc = location;
    pctInfected = percentInfected;
    pctDead = percentDead;
    hasImmunity = hsImmunity;
    stateCount = count;
    contagiousCount = contagCount;
    incubatingCount = incubCount;
}

Square *Resident::getBestMove(){
    Square *tmp;
    for (int i=0; i<4; i++) {
        tmp = loc->getNext(i);
        if (tmp == homeLoc) {
            return tmp;
        }
        if (tmp && !tmp->isHouse() && closer(tmp, loc) && tmp != previousLoc) {
            return tmp;
        }
    }
    
    /*if can't find any square closer to home, move to whichever street*/
    while (true) {
        int rd = rand() % 4;
        tmp = loc->getNext(rd);
        if (tmp && !tmp->isHouse() && tmp != previousLoc) {
            break;
        }
    }
    return tmp;
    
}

state Resident::getCondition() const{
    return con;
}

Square * Resident::getHomeLoc() const{
    return homeLoc;
}

Square * Resident::getLoc() const{
    return loc;
}

Square *Resident::getPreviousLoc() const{
    return previousLoc;
}

int Resident::getDirectionOfMoving(){
    if(loc->getY() - previousLoc->getY() < 0)
        return 0; /*up*/
    else if(loc->getX() - previousLoc->getX() > 0)
        return 1; /*right*/
    else if(loc->getY() - previousLoc->getY() > 0)
        return 2; /*down*/
    else if(loc->getX() - previousLoc->getX() < 0)
        return 3; /*left*/
    else
        return 4; /*not moving*/
}

float Resident::getPercentInfected() const{
    return pctInfected;
}

bool Resident::getHasImmunity() const{
    return hasImmunity;
}

void Resident::setLoc(Square *newLoc){
    loc = newLoc;
}



void Resident::setHomeLoc(Square *homeLocation){
    homeLoc = homeLocation;
}

void Resident::setCondition(state cond){
    con = cond;
    stateCount = 0;
}

void Resident::initCondition(state condition){
    this->con = condition;
    if(con == incubating)
        stateCount = rand() % incubatingCount;
}




void Resident::setUp(float percentInfected,
                     float percentDead,
                     bool hadImmunity,
                     int contagiousCount,
                     int incubatingCount,
                     int blocksPerDay,
                     int pctOnStreet
                     )
{
    this->previousLoc = this->loc;
    this->pctInfected = percentInfected;
    this->pctDead = percentDead;
    this->hasImmunity = hadImmunity;
    this->contagiousCount = contagiousCount;
    this->incubatingCount = incubatingCount;
    
    /*out of 60% travelling, the resident will travel randomly for 60%,
     then he starts to go home
     */

    this->blocksPerDay = blocksPerDay;
    this->pctOnStreet = pctOnStreet;
    this->travelCountLimit = this->blocksPerDay * this->pctOnStreet / 100 * 60 /100;
    this->stayHomeCountLimit = this->blocksPerDay * (100 - this->pctOnStreet)/100;
    stateCount= 0; /*installize statecount*/
    travelCount= 1; /*start moving*/
    stayHomeCount= 0;/*not stay home*/

}

void Resident:: incrementStateCount(){
    stateCount++;
}

void Resident::resetStateCount(){
    stateCount = 0;
}

bool Resident::isTravelling() const{
    return travelCount < travelCountLimit && !isAtHome();
}

bool Resident::isGoingHome() const{
    return travelCount == travelCountLimit;
}

bool Resident::isAtHome() const{
    return stayHomeCount;
}

void Resident::move(){
    Square *tmpLoc;
    if(this->isTravelling()){
        while(true){
            tmpLoc = loc->getRandomMove();
            if (tmpLoc == previousLoc) {
                continue;
            }
            if(!tmpLoc->isHouse())
                break;
        }
        previousLoc = loc; /*save previous location before moving*/
        loc = tmpLoc;
        if (getCondition() == contagious) {
            loc->spreadDisease();
        }
        travelCount++;
    }
    
    else if(this->isGoingHome()){
        Square *tmp = loc;
        loc = getBestMove();
        previousLoc = tmp;
        if(loc == homeLoc){ /*if arrived home*/
            travelCount = 0; /*reset travel count*/
            stayHomeCount = 1; /*start staying home*/
        }
        else if (getCondition() == contagious) {/*the square is infective if this resident is infected*/
            loc->spreadDisease();
        }
    }
    
    else if(isAtHome()){/*is at home*/
        previousLoc = loc;
        stayHomeCount++;
        if(stayHomeCount == stayHomeCountLimit){ /*if stay home enough*/
            stayHomeCount = 0; /*reset stayHome count*/
            travelCount = 1; /*start going out*/
        }
    }
    else {
        std::cout << "error" << endl;
    }
    if(!loc ->isHouse() && con == contagious)
    {
        loc->setInfective(true);/*set infected square*/
		for (int i =0; i<4; i++) {
			/*(if loc->getnext is not equal to null)*/
			/*set this loc infective square*/
			if (loc->getNext(i) && !loc->getNext(i)->isHouse()) {
				loc->getNext(i)->setInfective(true);
			}
		}
    }
}


/*
 private method to determine if the temp location is closer to home
 then the current location
 */
bool Resident::closer(Square *temp, Square *current){
    if( abs(temp->getX() - homeLoc->getX()) < abs(current->getX() - homeLoc->getX() )
       || abs(temp->getY() - homeLoc->getY()) < abs(current->getY() - homeLoc->getY()))
    {
        return true;
    }
    return false;
}

void Resident::updateHealthCondition(){
    Square *current = getLoc(); /*current square*/
    state cond = getCondition();
    
    switch(cond)
    {
        case healthy:
            if (current->isInfected() && rand() % (100 * 1000) < getPercentInfected() * 1000)
                setCondition(incubating);
            break;
        case incubating:
            if (stateCount < incubatingCount) {
                stateCount++;
            }
            else {
                setCondition(contagious);
            }
            break;
            
        case contagious:
            if (stateCount < contagiousCount) {
                stateCount++;
                break;
            }
            
            else{
                if (rand() % (100 * 1000) < pctDead * 1000) { /* less than this %, dead*/
                    setCondition(dead);
                }
                else {
                    if(hasImmunity)
                        setCondition(immuned);
                    else 
                        setCondition(healthy);
                    /*if immuned, hasImmuned = true*/
                }
            }
            break;
        default:	/*if dead and immuned, state won't change*/
            break;
    }
}

void Resident::print(){
    cout << "resident info: " << endl;
    cout << "home location: ";
    this->getHomeLoc()->print();
    cout << "current location: ";
    this->getLoc()->print();
    cout << "health condition: ";
    cout << this->getCondition(); cout << endl;
    cout << "state count: " << stateCount << endl;
}
