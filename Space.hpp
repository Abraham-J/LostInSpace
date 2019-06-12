/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file of Space class, an abstract class.
 ********************************/
#include <string>

#ifndef SPACE_HPP
#define SPACE_HPP

class Space{
    
protected://Variables available to all the derived classes
    
    std::string type;
    std::string character;
    Space ***spaceArray;
    
    Space * up;
    Space * down;
    Space * left;
    Space * right;
    
    
    int row;
    int col;
    
    
public://Constructors, destructors and methods
    Space();
    void setMap(Space *, Space *, Space *, Space *);
    std::string getType();
    std::string getCharacter();
    Space * getUp();
    Space * getDown();
    Space * getLeft();
    Space * getRight();
    
    
};
#endif
