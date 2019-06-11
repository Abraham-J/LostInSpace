/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Gold class, derived from Gold class
 ********************************/
#include "Gold.hpp"

#include <string>
using std::string;

Gold::Gold(){
    name = "Gold";
    type = "Extracted";
    description = "A highly precious metal. Resistant to corrosion, but conductive of electricity, leading it to be a very useful metal for electrical componenets.";
    baseSellPrice = 250;
}
