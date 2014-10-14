#include <iostream>
#include <string>
#include <fstream>
#include "Volunteer.h"

using namespace std;
const int SIZE = 12; //12! permutations



bool loadFile(string filename, struct Person[]); //load from file into the array
void findBest(Volunteer list[]); //find all possible permutations and add up the results of each
int calcPoints(Volunteer list[]);



int main(void)
{
	Volunteer list[SIZE];
	if (loadFile(list)){} //load from file intro array of class
	else
	{
		cout << "could not load file";
		return 0;
	}
}

bool loadFile(Volunteer list[])
{
	string name = NULL;
	int first = 0;
	int second = 0;
	int third = 0;
	int i = 0;

	ifstream inputFile;
	inputFile.open("volunteers.txt"); //open data file

	for(i = 0; i < SIZE; ++i) 	//load into array of struct one by one
	{
		inputFile >> name >> first >> second >> third;
		list[i].setName(name);
		list[i].setFirst(first);
		list[i].setSecond(second);
		list[i].setThird(third);
	}
}

void findBest(Volunteer list[])
{
	int score;
	//go through permutations and calculate the values
	
	//call calcPoints function to calculate for each array

	score = calcPoints(list);

}

int calcPoints(Volunteer list[])
{
	int i;
	int month;
	int score = 0;
	bool months[12];
	for(i = 0; i < SIZE; ++i)
	{
		month = list[i].getFirst(); //check first choice availibility 
		if(months[month-1])
		{
			score += 3;
			months[month-1] = false;
		}
		else
		{
			month = list[i].getSecond();  //check second choice availibility 
			if(months[month-1])			  //if first not available
			{
				score += 2;
				months[month-1] = false;
			}
				
			else
			{
				month = list[i].getThird(); //check third choice availibility
				if(months[month-1])			//if first and second not available
				{
					score += 1;
					months[month-1] = false;
				}
			}
		}
	}
}
