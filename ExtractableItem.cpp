/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of ExtractableItem class, derived from Item class
 ********************************/

#include "ExtractableItem.hpp"
#include <string>
using std::string;

ExtractableItem::ExtractableItem(){

}
int ExtractableItem::getExtractionCost(){
    return extractionCost;
}
