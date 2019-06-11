/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Radar class, derived from RepairableItems class
 ********************************/
#include "Radar.hpp"
#include "RepairableItem.hpp"
#include "KeyItem.hpp"
#include <string>
using std::string;

Radar::Radar(){
    name = "Multiangle Radar";
    type = "Utility";
    description = "Can find cloaked ships, by tracking trace beams of energy.";
    repairCost = 250;
}
