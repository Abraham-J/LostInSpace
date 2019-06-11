/******************************************************************************
 * Author: Sanjo Abraham
 * Date: 5/6/2019
 * Description: This is the header file for the random number generator.
 *****************************************************************************/
#ifndef RNG_HPP
#define RNG_HPP
#include <random>
class RNG
{
private:
	std::random_device device;			//random number device for seeding
	std::mt19937 engine{ device() };	//random-bit-generator engine

public:
	int intGen(int min, int max);
    
};

#endif
