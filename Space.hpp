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
    std::string **strArray;
    
    struct SpaceNode{
        Space * up;
        Space * down;
        Space * left;
        Space * right;
    };
    
    SpaceNode * head;
    
    int row;
    int col;
    
    
public://Constructors, destructors and methods
    Space();
    void setArray(int, int);
    std::string getType();
    std::string getCharacter();
    
    virtual void DoActivity(int);
    
    
};
#endif
