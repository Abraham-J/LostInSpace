/******************************************************************************
 * Author: Sanjo Abraham
 * Date: 5/6/2019
 * Description:
 * This is the implement file for the RNG class. 
 *****************************************************************************/
#include "RNG.hpp"
using std::uniform_int_distribution;
/******************************************************************************
Description: This generates a random integer within the range passed into it.
******************************************************************************/
int RNG::intGen(int min, int max)
{
	uniform_int_distribution<int> generator{ min, max };
	return generator(engine);
}

///******************************************************************************
// Description: This generates a random integer within the range passed into it.
// ******************************************************************************/
//double RNG::floatGen(double min, double max)
//{
//    uniform_int_distribution<double> generator{ min, max };
//    return generator(engine);
//}
