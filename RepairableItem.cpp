/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of RepairableItem class, an abstract class also derived from KeyItem
 ********************************/
#include "RepairableItem.hpp"
#include <string>
using std::string;

RepairableItem::RepairableItem(){
    
}

/********************************
getter functions for the repair cost
 ********************************/
int RepairableItem::getRepairCost(){
    return repairCost;
}

