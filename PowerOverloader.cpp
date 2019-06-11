/*******************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of PowerOverloader class
 ********************************/
#include "PowerOverloader.hpp"

#include <string>
using std::string;

PowerOverloader::PowerOverloader(){
    name = "Power Overloader";
    type = "Bought";
    description = "Provides a slight boost to a ships power power capacity.";
    baseCost = 300;
    baseSellPrice = 300;
}
