/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file for RepairableItem functions, RepairableItem is a derived class of KeyItems
 ********************************/
#include "KeyItem.hpp"
#ifndef REPAIRABLEITEM_HPP
#define REPAIRABLEITEM_HPP
#include <string>
#include <vector>

class RepairableItem: public KeyItem{
    protected:
        int repairCost;
        std::string repaired;
    public:
    RepairableItem();
    int getRepairCost();
};

#endif
