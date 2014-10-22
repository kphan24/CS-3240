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

	switch (input) 
	{
		case 'S':
			cout << "You have chosen to set up a new semester" << endl;
			newSemester();
			break;
		case 'A':
			cout << "You have chosen to add a new student" << endl;
			newStudent();
			break;
		case 'T':
			cout << "You have chosen to record test grades for all students" << endl;
			recordTest();
			break;
		case 'P':
			cout << "You have chosen to record assignment grades for all students" << endl;
			recordAssignment();
			break;
		case 'F':
			cout << "You have chosen to record final exam grades for all students" << endl;
			recordExam();
			break;
		case 'G':
			cout << "You have chosen to calculate the overall grade for all students" << endl;
			calcGrade();
			break;
		case 'C': 
			cout << "You have chosen to change a student's grade" << endl;
			changeGrade();
			break;
		case 'O':
			cout << "Grades for all students displayed below" << endl;
			displayData();
			break;
		case 'Q':
			return false;
			break;
		default:
			cout << "Invalid input, please try again." << endl;
			break;
	}

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
