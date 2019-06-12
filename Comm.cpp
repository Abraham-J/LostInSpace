/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Comm class, derived from RepairableItems class
 ********************************/
#include "Comm.hpp"
#include "RepairableItem.hpp"
#include "KeyItem.hpp"
#include <string>
using std::string;

Comm::Comm(){
    name = "Communication Device";
    type = "Comm";
    repairStatus = "U";
    description = "Low frequency, communication device that alows subspace communication.";
    repairCost = 1500;
}
