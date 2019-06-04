/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file of Activities class, an abstract class.
 ********************************/
#include <string>

#ifndef ACTIVITIES_HPP
#define ACTIVITIES_HPP

class Activities{
    
protected://Variables available to all the derived classes
    std::string type;
    
public://Constructors, destructors and methods
    std::string getType();
};
#endif
