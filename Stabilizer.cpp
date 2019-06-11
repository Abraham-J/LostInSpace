/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Stabilizer class, derived from RepairableItems class
 ********************************/
#include "Stabilizer.hpp"
#include "RepairableItem.hpp"
#include "KeyItem.hpp"
#include <string>
using std::string;

Stabilizer::Stabilizer(){
    name = "Material Stabilizer";
    type = "Repairable";
    description = "Prevents decay of matter into other dimensions by preventing supposition of the ship's particles. Allow's for safe passage through Nebulas.";
    repairCost = 400;
}
