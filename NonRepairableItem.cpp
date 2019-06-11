#include "NonRepairableItem.hpp"

#include <string>
using std::string;
NonRepairableItem::NonRepairableItem(){

}

void NonRepairableItem::setPreReq(bool hasItem){
    preReqMet = hasItem;
}
