/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Scrap class, derived from Scrap class
 ********************************/
#include "Scrap.hpp"

#include <string>
using std::string;

Scrap::Scrap(){
    name = "Scrap";
    type = "Extracted";
    description = "Mostly useless. A scrapper might be able to salvage some material out of this.";
    baseSellPrice = 40;
}
