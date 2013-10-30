//#ifndef RESIDENT_H
//#define RESIDENT_H

//#endif // RESIDENT_H


/**
 @file resident.h
 */



#include "square.h"
#include <vector>

#define DAY 20

using namespace std;

/*!
 @enum state
 @discussion Health conditions
 */
enum state {
    healthy = 0, /**< The resident has never gotten the disease before */
    incubating = 1, /**<The resident catched the disease but has not ben contagious.
                     He can't pass the disease to other.*/
    contagious = 2, /**<The resident have the disease and is contagious*/
    immuned = 3, /**<The resident is immumed from the disease*/
    dead = 4 /**<The resident died*/
};





/*!
 @class Resident
 @brief An individual person in the population
 */
/**
 @discussion Residents are the interactive components of the simulation.
 By traveling around, the residents can get infected from or pass the disease
 to other residents who are on the same location (square).\n
 Each resident has a house that nobody else can enter. By staying at home, the
 residents are isolated from the rest of the poplation, thus cannot get infected
 or infect others.\n
 Different residents have different ability to fight against the disease. Some
 residents are eaiser to get infected than others. Some residents are cured in
 less amount of time than others.\n
 Different residents also have different schedules. The amounts of time they
 spend on the street or at home are veried among the poplation.
 
 */
class Resident{
    
private:
    state con; /**<health condition*/
    int stateCount; /**<state count*/
    int travelCount; /**<travel count*/
    int stayHomeCount; /**<stay home count*/
    
    Square * homeLoc; /**<home location*/
    Square * loc; /**<current location*/
    Square * previousLoc;
    
    float pctInfected; /**<% chance for this resident to get infected*/
    float pctDead; /**<% chance for dead*/
    
    bool hasImmunity; /**<the disease has the immunity*/
    
    
    int contagiousCount; /**<contagious count*/
    int incubatingCount; /**<incubating count*/
    
    int travelCountLimit; /**<if travelCount reach this limit, start going home*/
    int stayHomeCountLimit;

    int blocksPerDay;
    int pctOnStreet;

    bool closer(Square *temp, Square *current); /**<move one square closer to home*/
    Square *getBestMove();
    
public:
    
    /**
     @brief Default constructor
     */
    /**
     @discussion
     */
    Resident();
    
    
    /**
     @brief Detailed constructor
     */
    /**
     @discussion
     @param condition This resident's health condition
     @param homeLocation This resident's home location
     @param location This resident's current location
     @param prcentAtHome Percentage of time this resident spend at home
     @param prcentInfected Percentage chance this resident will be infected
     @param hsImmunity This person has immunity or not
     */
    Resident(state condition,
             Square *homeLocation,
             Square *location,
             float prcentInfected,
             float prcentDead,
             bool hsImmunity,
             int count, int infect, int cure);
    
    /**
     @brief Retrieves the health condition of this resident
     */
    /**
     @discussion
     @return this resident's health condition
     */
    state getCondition() const;
    
    
    /**
     @brief Retrieves the home location of this resident
     */
    /**
     @discussion
     @return this resident's home location
     */
    Square * getHomeLoc() const;
    
    
    /**
     @brief Retrieves the current location of this resident
     */
    /**
     @discussion
     @return this resident's current location
     */
    Square * getLoc() const;
    
    /**
     @brief Retrieves the previous location
     */
    /**
     @discussion
     @return this resident's previous location
     */
    Square *getPreviousLoc() const;

    int getDirectionOfMoving();
    
    
    /**
     @brief Retrieves the percentage of time this resident
     spend at home
     */
    /**
     @discussion
     @return the percentage of time this resident spend at
     home
     */
    float getPercentTravelling() const;
    
    
    /**
     @brief Retrieves the percentage chance this resident
     gets infected
     */
    /**
     @discussion
     @return the percentage chance this resident gets infected
     */
    float getPercentInfected() const;
    
    float getPercentDead();
    
    
    /**
     @brief Returns true if this resident has immunity against
     the disease
     */
    /**
     @discussion
     @return true if this resident has the immunity against
     the disease, false otherwise
     */
    bool getHasImmunity() const;
    
    
    /**
     @brief Sets the current location of this resident
     */
    /**
     @discussion
     @param newLoc the new location of this resident
     */
    void setLoc(Square *newLoc);
    
    /**
     @brief Sets the home location of this resident
     */
    /**
     @discussion
     @param homeLocation the home location of this resident
     */
    void setHomeLoc(Square *homeLocation);
    
    
    /**
     @brief Ramdomly moves one square or stay in the same place
     */
    /**
     @discussion Makes a random move based on the
     available moves from the square that the resident
     is currently on
     */
    void move();
    
    
    /**
     @brief Moves one square towards home
     */
    /**
     @discussion If this resident is already home, he does not move
     */
    void goHome();
    
    
    /**
     @brief Updates this resident's health condition
     */
    /**
     @discussion
     */
    void updateHealthCondition();
    
    /**
     @brief set Health Condition
     */
    /**
     @discussion
     */
    void setCondition(state cond);
    
    /**
     @brief initialize the health condition
     */
    /**
     @discussion This method picks a random number for the stateCount
     @param healthState the health condition of this resident
     */
    void initCondition(state healthState);
    
    
    /**
     @brief Returns true if this resident is travelling
     */
    /**
     @discussion
     @return true if this resident is travelling around
     */
    bool isTravelling() const;
    
    /**
     @brief Returns true if this resident is going home
     */
    /**
     @discussion
     @return true if this resident is on the way home
     */
    bool isGoingHome() const;
    
    /**
     @brief Returns true if this resident is at home
     */
    /**
     @discussion
     @return true if this resident is at home
     */
    bool isAtHome() const;
    
    int getStateCount() const;
    void incrementStateCount();
    void resetStateCount();
    
    
    
    void setUp(float percentInfected,
               float percentDead,
               bool hadImmunity,
               int contagiousCount,
               int incubatingCount,
               int blocksPerDay,
               int pctOnStreet
               );
    
    void print();
};
