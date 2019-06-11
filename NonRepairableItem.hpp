/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file for NonRepairableItem functions, NonRepairableItem is an abstract class of KeyItem
 ********************************/
#include "KeyItem.hpp"
#ifndef NONREPAIRABLEITEM_HPP
#define NONREPAIRABLEITEM_HPP
#include <string>
#include <vector>

class NonRepairableItem : public KeyItem{
    protected:
        bool preReqMet;
    public:
    NonRepairableItem();
    void setPreReq(bool);
};

#endif
