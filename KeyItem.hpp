/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Header file for KEYITEM functions, KEYITEM is an abstract class
 ********************************/

#ifndef KEYITEM_HPP
#define KEYITEM_HPP
#include <string>
#include <vector>

class KeyItem{
    protected:
    std::string name;
    std::string type;
    std::string description;
    std::string repairStatus;
    public:
    KeyItem();
    std::string getName();
    std::string getType();
    std::string getRepairStatus();
    void setRepairStatus(std::string);
    std::string getDescription();
};

#endif
