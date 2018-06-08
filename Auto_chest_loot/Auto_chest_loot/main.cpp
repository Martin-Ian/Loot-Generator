//Made by Ian Martin in June 2018
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <time.h>

using namespace std;

int get_Random_Value(int min, int max);
//Simple random number generator, generates a random number between min <= rand < max

int main(void)
{
	//Resets the random seed
	srand(time(0));

	for (int i = 0; i < 1000; i++)
	{
		cout << get_Random_Value(0, 100) << " ";
	}

	return 0;
}

//Random number generator
int get_Random_Value(int min, int max)
{
	if (min >= max)
	{
		return min;
	}

	int difference = max - min;

	return rand() % difference + min;
}
