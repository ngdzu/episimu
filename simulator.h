
#include <vector>
#include "resident.h"


using namespace std;


typedef struct{
    int x, y;
}coordinate;

class Simulator{

private:
    Square ** grid;
    Resident *resident; /*all residents*/
    
    
    bool *infectedResidents;
    
    /*location of all houses, needed for assigning houses to residents*/
    vector<Square *> availableHouse;
    
    int side; /*a grid is always a square, this is the side of the square*/
    int numDead; /*number of dead people*/
    int numInstance; /*the number of days the simulator has run*/
    
    int numCase; /*number of infected cases*/
    
    int populationSize;
    bool dense; /*a lot of people in the city*/
    double percentStartedWithDisease;
    double percentGetInfected;
    double percentDead;
    bool hasImmunity; /*the disease has the immunity or not*/


    int incubatingTime;
    int contagiousTime;

    int blocksPerDay;
    int pctOnStreet;

    vector<int> infectionPlot; /**<used for plotting infection graph*/
    vector<int> deathPlot; /**<used for plotting death graph*/
    vector<int> timesTrasmittedPlot; /**<used for plotting # of transmission plot*/


	void initGrid();
    void initPopulation();
    
public:
	
	
	Simulator();
	
	
	/**
	 @brief Detailed constructor
	 */
	/**
	 @discussion
	 @param gridSize The size of the grid
     @param dense if dense = true, 80% houses have owners, otherwise, 40%
	 @param populationSize The total number of the residents
	 @param percentStartedWithDisease The percentage of the population
	 who are infected when the simulation starts
	 @param percentGetInfected The probability of getting the disease
	 from other infected residents
	 @param immuned equals true if the resident can develop immunity 
	 against the disease, thus won't get infected again. 
	 @param incubatingTime The duration from getting infected until being
	 contagious
	 @param infectingTime The duration of time from getting infected until
	 being cured or dead
	 */
    Simulator(
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
			  );
	

    ~Simulator();
	
    void run();

    /*return the pointer to the array of all residents*/
    Resident *getResident();

    int getSide();
	
    int getNumDead();
    
    int getNumInfected();
    
    int getNumCase();
    
    
    /*return the number of days passed since the simulation started*/
    int getTimeRun();
    
    int getNumInstance();

    bool runOneInstance();

    vector<int> *getInfectionPlot(){
        return &infectionPlot;
    }

    vector<int> *getDeathPlot(){
        return &deathPlot;
    }

    vector<int> *getTimesTransmittedPlot(){
        return &timesTrasmittedPlot;
    }


    
};
