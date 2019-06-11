/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file for Item functions, Item is an abstract class
 ********************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <vector>

class Item{
    private:
            std::string name;
            std::string description;
            int baseCost;
            int baseSellPrice;

    public:
        Item();
};

#endif
