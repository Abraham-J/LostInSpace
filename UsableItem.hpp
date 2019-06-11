/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file for usableitem functions, usableItem is an derived class of Item
 ********************************/
#include "Item.hpp"
#ifndef USABLEITEM_HPP
#define USABLEITEM_HPP
#include <string>
#include <vector>

class UsableItem : public Item{
    protected:
    int baseCost;

    public:
    UsableItem();
    int getCost();
};

#endif
