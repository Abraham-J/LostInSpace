/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file of Debris class, a derived class of Space.
 ********************************/

#ifndef DEBRIS_HPP
#define DEBRIS_HPP
#include "Space.hpp"
#include <string>

class Debris : public Space{
    
private://Variables


    
public://Constructors, destructors and methods
    Debris();
    void DoActivity(int);
};
#endif
