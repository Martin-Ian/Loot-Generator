//Made by Ian Martin in June 2018
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

int get_Random_Value(int min, int max);
//Simple random number generator, generates a random number between min <= randnum < max

vector<string> file_parser(ifstream* file_to_parse);
//custom file parser to collect relevent data from the loot file

int main(void)
{
	//Resets the random seed
	srand(time(0));

	cout << "Welcome to the loot generator!" << endl;
	cout << "Please enter the name of your loot file: -> ";

	string file_name;
	getline(cin, file_name);

	ifstream file_to_open;

	file_to_open.open(file_name);

	if (file_to_open.good())
	{
		vector<string> data = file_parser(&file_to_open);
		
		for (auto point : data)
		{
			cout << point << endl;
		}
	}
	else
	{
		cout << "Error opening file. Now exiting." << endl;
		return 0;
	}

	return 0;
}

//Random number generator
int get_Random_Value(int min, int max)
{
	//failsafe incase invalid operands
	if (min >= max)
	{
		return min;
	}

	//need to modulo the stl rand() by the difference between min and max
	int difference = max - min;

	return rand() % difference + min;
}

vector<string> file_parser(ifstream* file_to_parse)
{
	//vector of strings to hold the info
	vector<string> data{};

	while (file_to_parse->good())
	{
		string current_line;
		getline(*file_to_parse, current_line);
		data.push_back(current_line);
	}

	//close the file
	file_to_parse->close();

	return data;
}