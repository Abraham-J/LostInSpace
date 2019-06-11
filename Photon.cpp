/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Photon class, derived from RepairableItems class
 ********************************/
#include "Photon.hpp"
#include "RepairableItem.hpp"
#include "KeyItem.hpp"
#include <string>
using std::string;

Photon::Photon(){
    name = "Photon Torepedo";
    type = "Weapon";
    description = "Warhead filled with antimatter that is launched using plasma exhaust. Can be attached to a ship's hull to increase it's attack power.";
    repairCost = 150;
}
