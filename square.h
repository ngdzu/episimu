//#ifndef SQUARE_H
//#define SQUARE_H

//#endif // SQUARE_H



/**
 @file square.h
 */


/*!
 @class Square
 @brief The smallest unit representing a location on the grid.
 */
/**
 @discussion
 It contains a pair of coordinates that locate exactly
 where the object is on the grid.\n
 A square can either be a house or street. \n
 \n
 A street can be infective or not.\n
 All healthy residents who walk on an infective street have a chance
 to get infected.\n
 If the street is infective, attribute isInfective is set to true,
 otherwise false.\n
 A street can be adjacent to the maximum of 4 other streets.\n
 <table>
 <tr>
 <td>H</td>
 <td>T</td>
 <td>H</td>
 </tr>
 <tr>
 <td>L</td>
 <td>C</td>
 <td>R</td>
 </tr>
 <tr>
 <td>H</td>
 <td>B</td>
 <td>H</td>
 </tr>
 </table>
 In the diagram above, current street C is adjacent to the streets T, R, B, and L.
 All H's are houses. \n
 The adjacent streets are stored in an array of pointer: Square *next[4]\n
 
 We denote the directions of the adjacent streets using number:\n
 <ul>
 <li>0 = top</li>
 <li>1 = right</li>
 <li>2 = bottom</li>
 <li>3 = left</li>
 </ul>
 Example:\n
 <ul>
 <li>The adjacent street to the left of current street is next[3].</li>
 <li>The adjacent street to the bottom of current street is next[2].</li>
 </ul>
 If a direction does not lead to another street, then next[direction] = null.
 
 */

#include<cstdlib>


class Square {
private:
    /*coordiate*/
    int x;
    int y;
    
    /*if this square is a house then house = true, otherwiser false*/
    bool house;
    
    /*if an infected resident is on this square, infected is set to true*/
    bool infective;
    
    /*possible move that a resident can make*/
    Square *next[4];
public:
    
    /**
     @brief Default constructor
     @discussion
     - x is set to 0
     - y is set to 0
     - house is false
     - infected is false
     - next point to null
     */
    Square();
    
    
    /**
     @brief Detailed constructor
     @param x x-coordinate
     @param y y-coordinate
     @param house true if this square is house, false otherwise
     @param infected true if this square is infected, false otherwise
     */
    Square(int x, int y, bool house);
    
    /**
     @brief Retrieves  the location of this square
     */
    /**
     @return the pointer to this square
     */
    Square *getLoc();
    
    /**
     @brief Retrieves the x-coordinate
     */
    /**
     @discussion This method is used to get the x-coordinate of this square
     @return the x-coordinate
     */
    int getX() const;
    
    /**
     @brief Retrieves the y-coordinate.
     */
    /**
     @discussion This method is used to get the y-coordinate of this square
     @return the y-coordinate
     */
    int getY() const;
    
    /**
     @brief Returns true if this square is a house
     */
    /**
     @return true if this square is a house, false if it is a street
     */
    bool isHouse() const;
    
    /**
     @brief Returns true if this square is a medium for the diease transmission
     */
    /**
     @discussion When an infected resident is present on a square, that square
     becomes a medium for the disease to transmit. If other residents are also
     on that square, they can get infected.
     @return true if an infected resident is present on this square
     */
    bool isInfected() const;
    
    /**
     @brief Returns a Square pointer at the direction
     */
    /**
     @discussion
     @param direction 0 for top, 1 for right, 2 for bottom, 3 for left
     @return the pointer to the street at this direction
     */
    Square *getNext(int direction) const;
    
    /**
     @brief Ramdomly selected one square that is connected to current square, 
     (never return NULL)
     */
    /**
     @discussion
     @return the pointer to the randomly selected square that is connected to
     current square
     */
    Square *getRandomMove() const;
    
    /**
     @brief Sets the state (infective or not) for this street
     */
    /**
     @discussion
     @param state true if infective, false if not infective
     @return
     - true if successfully set (which means this square is a street)
     - false if not successfully set (which means this square is
     a house, can't be infective)
     */
    void setInfective(bool state);

    void spreadDisease();

    /**
     @brief Sets the coordinate for this square
     */
    /**
     @discussion
     @param x x-coordinate
     @param y y-coordinate
     */
    void setLoc(int x, int y);
    
    /**
     @brief Updates the current state (infective or not)
     of this street
     */
    /**
     @discussion
     */
    
    void setHouse(bool home);
    
    
    void setNext(Square *top, Square *right, Square *bottom, Square *left);
    
    //	void updateStreetState();
    
    void print();
};
