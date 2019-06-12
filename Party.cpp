/*******************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Party class
 ********************************/
#include "Party.hpp"

#include <string>
using std::string;

Party::Party(){
    name = "Party-in-a-box";
    type = "Morale";
    description = "Allows crew to have some much needed time off.";
    baseCost = 100;
    baseSellPrice = 100;
    boostVal = 10;
}
