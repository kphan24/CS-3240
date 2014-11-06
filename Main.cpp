/*
HW 5
Group 9
Khoa Phan, Patrick Heintz
*/

#include "MyStack.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void prefixToPostfix(MyStack fixList);
bool isOperator(string input);


int main(void)
{
    MyStack fixList;
    prefixToPostfix(fixList);

	return 0;
}


// conversion algorithm
void prefixToPostfix(MyStack fixList)
{
    int numCount = 0;
    ifstream inputFile;
    inputFile.open("iFile.txt");     //open input file
    ofstream oFile;
    oFile.open("oFile.txt");
    string temp;
    string line;

    //open / create output file
    //start reading in
    while(inputFile)
    {
        getline(inputFile, line);
		istringstream iss(line);  //put line into stream
        oFile << "Prefix:  " << line << endl;
        oFile << "Postfix: ";
		numCount = 0;

        while(iss >> skipws >> temp) //get word by word
		{
		    //cout << temp << " ";
			if(!isalpha(temp[0]))
            {
                fixList.push(temp); //if operator, move to top of list
                numCount = 0;  //reset operand count to 0 due to operator
                //cout << "pushing " << temp;
            }
			if (isalpha(temp[0]))
			{
				oFile << temp << " "; //if alphabetical, print to file
				++numCount;
			}
			if (numCount == 2) //if two operands in a row print to file
			{
				oFile << fixList.pop() << " ";
				numCount = 0;
			}
		}
		while(fixList.getSize() > 0)
            oFile << fixList.pop() << " ";
        cout << endl;
		oFile << endl << endl;
	}
	inputFile.close();
	oFile.close();
}
