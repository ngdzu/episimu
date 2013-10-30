
/*
 *  square.cpp
 *  Epidemic
 *
 *  Created by AKOMN on 3/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "square.h"
#include <iostream>

using namespace std;

Square::Square(){
    /*default constructor does nothing*/
}

Square::Square(int x, int y, bool house){
    this->x = x;
    this->y = y;
    this->house = house;
    
}

Square* Square::getLoc(){
    return this;
}

int Square::getX() const{
    return x;
}

int Square::getY() const{
    return y;
}

bool Square::isHouse() const{
    return house;
}

bool Square:: isInfected() const{
    return infective;
}

void Square::setHouse(bool home){
    house = home;
}

void Square::setNext(Square *top, Square *right, Square *bottom, Square *left){
    next[0] = top;
    next[1] = right;
    next[2] = bottom;
    next[3] = left;
}


Square* Square::getNext(int direction) const{
    return next[direction];
}

Square* Square::getRandomMove() const{
    Square *tmpSquare;
    while(true){
        tmpSquare = next[rand() % 4];
        if(tmpSquare)
            break;
    }
    return tmpSquare;
}

void Square::setInfective(bool cond){
    infective = cond;
}

void Square::spreadDisease(){
    for(int i=0; i<4 ; i++){
        if(next[i] && !next[i]->isHouse()){
            next[i]->setInfective(true);
        }
    }
}

void Square::setLoc(int x, int y){
    this->x = x;
    this->y = y;
}

void Square::print()
{
    
    cout << "X = " << getX() << ", Y= "<< getY()<< endl;
    
    if(house)
        cout<< "this is a house"<< endl;
    
    //    Square *top= next[0];
    //    Square *right= next [1];
    //    Square *bottom= next[2];
    //    Square *left = next[3];
    
    
    
    //    if(top)
    //        cout << "top location: X= " << top -> getX()<< " Y =" << top -> getY() << endl;
    //    if (bottom)
    //        cout << "bottom location: X= " << bottom -> getX()<< " Y =" << bottom -> getY() << endl;
    //    if (left)
    //        cout << "left location: X= " << left -> getX()<< " Y =" << left -> getY() << endl;
    //    if (right)
    //        cout << "right location: X= " << right -> getX()<< " Y =" << right -> getY() << endl;
    
    cout << endl;
    
}


//void Square::updateStreetState(){
//
//}
