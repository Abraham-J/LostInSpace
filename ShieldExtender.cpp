/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of ShieldExtender class, derived from RepairableItems class
 ********************************/
#include "ShieldExtender.hpp"
#include "RepairableItem.hpp"
#include "KeyItem.hpp"
#include <string>
using std::string;

ShieldExtender::ShieldExtender(){
    name = "Shield Extender";
    type = "Repairable";
    description = "Employs an ion force field over parts of the ships, preventing items from causing damage to the ship's hull.";
    repairCost = 600;
}
