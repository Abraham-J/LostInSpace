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
    protected:
    std::string name;
    std::string type;
    std::string description;
    int baseSellPrice;

    public:
    Item();
    std::string getName();
    std::string getType();
    std::string getDescription();
    int getSellPrice();
};

#endif
