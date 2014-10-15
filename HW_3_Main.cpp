#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Volunteer.h"

using namespace std;
const int SIZE = 12; //12! permutations



bool loadFile(Volunteer list[]); //load from file into the array
void findBest(Volunteer list[]); //find all possible permutations and add up the results of each
int calcPoints(Volunteer list[], int pScore);
void printList(Volunteer list[], int score);



int main(void)
{
	Volunteer list[SIZE];
	if(loadFile(list) == false)
    {
        cout << "Could not load file.";
        return 0;
	} //load from file intro array of class

	findBest(list);

	return 0;

}

bool loadFile(Volunteer list[])
{
	string name;
	int first = 0;
	int second = 0;
	int third = 0;
	int i = 0;
	ifstream inputFile;
	inputFile.open("volunteers.txt");
	if(inputFile.is_open())
    {
        cout << "File open\n";
    }
    else
        return false;
	for(i = 0; i < SIZE; ++i) 	//load into array of struct one by one
	{
		inputFile >> name >> first >> second >> third;
		list[i].setName(name);
		list[i].setFirst(first);
		list[i].setSecond(second);
		list[i].setThird(third);
	}

	inputFile.close();
	return true;
}

void findBest(Volunteer list[])
{
	int score = 0;
	//go through permutations and calculate the values

    //find total number of permutations using n factorial
    int nfactorial = 1;
    Volunteer temp;
    int i, k, j;
    //calculate the number of perms using factorials
    for (i = 0; i < SIZE; ++i)
    {
        nfactorial *= i+1;
    }
    //print the first iteration of the list
    cout << "There are " << nfactorial << " permutations\n\n";
    score = calcPoints(list, score);

    for(i=1; i < nfactorial; ++i)
    {
        //move last element one by one to first elm
        for(k = SIZE-1; k > 0 ; --k)
        {
            temp = list[k];
            list[k] = list[k-1];
            list[k-1] = temp;
            score = calcPoints(list, score);
            ++i;
        }
        //now swap last two elms
        if(i < nfactorial)
        {
            temp = list[SIZE-1];
            list[SIZE-1] = list[SIZE-2];
            list[SIZE-2] = temp;
            score = calcPoints(list, score);
            ++i;
        }

        //now move first to last
        for(j=0; j < SIZE-1 && i < nfactorial; ++j, ++i)
        {
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;
            score = calcPoints(list, score);
        }
        //now swap the first two elements
        if(i < nfactorial)
        {
            temp = list[0];
            list[0] = list[1];
            list[1] = temp;
            ++i;
        }
    }
    return;
}

int calcPoints(Volunteer list[], int pScore)
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
			list[month-1].setAssigned(month);
			months[month-1] = false;

		}
		else
		{
			month = list[i].getSecond();  //check second choice availibility
			if(months[month-1])			  //if first not available
			{
				score += 2;
				list[month-1].setAssigned(month);
				months[month-1] = false;
			}

			else
			{
				month = list[i].getThird(); //check third choice availibility
				if(months[month-1])			//if first and second not available
				{
					score += 1;
					list[month-1].setAssigned(month);
					months[month-1] = false;
				}
				else
                    list[month-1].setAssigned(0);
			}
		}
	}
	if(score > pScore)
    {
        printList(list, score);
        return score;
    }
}

void printList(Volunteer list[], int score)
{
    int i = 0;
    cout << "SCORE: " << score << "\n\n";
    for(i = 0; i < SIZE; ++i)
    {
        cout << setw(20) << list[i].getName() << " " << list[i].getAssigned()
        << endl;
    }

    cout << endl;
    return;
}
