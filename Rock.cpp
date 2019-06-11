/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Rock class, derived from ExtractableItem class
 ********************************/
#include "Rock.hpp"

#include <string>
using std::string;

Rock::Rock(){
    name = "Space Rock";
    type = "Extract";
    description = "Asteroid fragments that can be refined into other material at high temperatures";
    baseSellPrice = 50;
    extractionCost = 25;
    
}
