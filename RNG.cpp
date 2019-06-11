/******************************************************************************
 * Author: Sanjo Abraham
 * Date: 5/6/2019
 * Description:
 * This is the implement file for the RNG class. 
 *****************************************************************************/
#include "RNG.hpp"
using std::uniform_int_distribution;
/******************************************************************************
Passed:		int min, int max
Returns:	int
Description: This generates a random integer within the range passed into it.
******************************************************************************/
int RNG::intGen(int min, int max)
{
	uniform_int_distribution<int> generator{ min, max };
	return generator(engine);
}

/******************************************************************************
 Passed:        float min, float max
 Returns:    int
 Description: This generates a random integer within the range passed into it.
 ******************************************************************************/
float RNG::floatGen(float min, float max)
{
    uniform_int_distribution<float> generator{ min, max };
    return generator(engine);
}
