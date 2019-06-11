/*******************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Deflector class
 ********************************/
#include "Deflector.hpp"

#include <string>
using std::string;

Deflector::Deflector(){
    name = "Deflector Array";
    type = "Bought";
    description = "Slows projectiles from approaching vital parts of ship. Can increase a ships shield capabilities";
    baseCost = 400;
    baseSellPrice = 400;
}
