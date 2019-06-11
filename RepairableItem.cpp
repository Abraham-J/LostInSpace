/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of RepairableItem class, an abstract class also derived from KeyItem
 ********************************/
#include "RepairableItem.hpp"

RepairableItem::RepairableItem(){
    
}

int RepairableItem::getRepairCost(){
    return repairCost;
}
