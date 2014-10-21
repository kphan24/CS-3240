#include "StudentList.h"
#include <iomanip>
#include <iostream>
#include <string>;
using namespace std;

char displayMenu();
void displayData();
int calcGrade();
bool getMenuInput();



int main()
{
	StudentList grades;
}

char displayMenu()
{
	char input;

	cout << "Please enter a command:" << endl;
	cout << "S" << setw(10) << right << "Set up a new semester\n";
	cout << "A" << setw(10) << right << "Add a student\n";
	cout << "P" << setw(10) << right << "Record assignment grade for all students\n";
	cout << "T" << setw(10) << right << "Record test grade for all studnts\n";
	cout << "F" << setw(10) << right << "Record final exam grade for all students\n";
	cout << "G" << setw(10) << right << "Calculate final grade\n";
	cout << "C" << setw(10) << right << "Change the grade of a student\n";
	cout << "O" << setw(10) << right << "Output the grade data\n";
	cout << "Q" << setw(10) << right << "Quit the program\n\n";

	cin >> input;
	return input;
}

bool getMenuInput()
{
	char input;
	input = displayMenu();
	input = toupper(input);

	if(input == 'S')
		newSemester();
	else if(input == 'A')
		newStudent();
	else if(input == 'T')
		recordTest();
	else if(input == 'P')
		recordAssignment();
	else if(input == 'F')
		recordExam();
	else if(input == 'G')
		calcGrade();
	else if(input == 'C')
		changeGrade();
	else if(input == 'O')
		displayData();
	else if(input == 'Q')
		return false;

	return true;
}

void recordGrade()
{

}
void newSemester()
{

}
void newStudent()
{

}
void recordAssignment()
{

}
void recordTest()
{

}
void recordExam()
{

}
void changeGrade()
{

}
void displayData()
{

}
int calcGrade()
{

}
