/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Phaser class, derived from RepairableItems class
 ********************************/
#include "Phaser.hpp"
#include "RepairableItem.hpp"
#include "KeyItem.hpp"
#include <string>
using std::string;

Phaser::Phaser(){
    name = "Phaser Rifles";
    type = "Phaser";
    repairStatus = "U";
    description = "Phases through material, causing it to completely incinerate. Can be attached to a ship's hull to increase it's attack power.";
    repairCost = 150;
}
