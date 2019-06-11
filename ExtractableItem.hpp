/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file for ExtractableItem functions, ExtractableItem is an derived class of Item
 ********************************/
#include "Item.hpp"
#ifndef EXTRACTABLEITEM_HPP
#define EXTRACTABLEITEM_HPP
#include <string>
#include <vector>

class ExtractableItem : public Item{
    protected:
    int extractionCost;
    
    public:
    ExtractableItem();
    int getExtractionCost();
};

#endif
