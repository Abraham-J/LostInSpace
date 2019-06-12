/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file for Warp functions, Warp is a derived class of NonRepairableItems
 ********************************/
#include "Warp.hpp"

#include <string>
using std::string;
Warp::Warp(){
    name= "Warp Drive";
    type= "Warp";
    repairStatus = "U";
    description= "Allows for the ship to operate at faster than the speed of light.";
}
