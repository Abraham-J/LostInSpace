/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file of Nebula class, a derived class of Space.
 ********************************/

#ifndef NEBULA_HPP
#define NEBULA_HPP
#include "Space.hpp"
#include <string>

class Nebula : public Space{
    
private://Variables
    
    
public://Constructors, destructors and methods
    Nebula();
    
    void DoActivity(int) override;
};
#endif
