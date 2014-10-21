#include "StudentList.h"
#include <iostream>
#include <string>
using namespace std;

struct NODE
{
	NODE *next;
	NODE *previous;
	int studentID;
	int assignments[6];
	int tests[4];
	int finalExam;
};
StudentList::StudentList(void)
{
}


StudentList::~StudentList(void)
{
}

NODE* StudentList::findStudent(int ID)
{
	NODE *ptr = *listNode;
	NODE newNode;
	newNode.studentID = ID;

	while (ptr->next && ID != ptr->studentID)
	{
		ptr = listNode.next;
	}
	if(ID != ptr->studentID)
	{
		cout << "Student not found\n";
		return;
	}
	else
		return ptr;
}
void StudentList::recordGrade(int grade)
{

}
void StudentList::newSemester(){}
void StudentList::newStudent(int ID)
{
	NODE *ptr = &listNode;
	NODE newNode;
	newNode.studentID = ID;

	while (ptr->next)
	{
		ptr = listNode.next;
	}
	listNode->next = newNode;
	newNode.next = 0;
	newNode.previous = ptr;
}
void StudentList::recordAssignment(int grade)
{
}
void StudentList::recordTest(int grade)
{
}
void StudentList::recordExam(int grade)
{
}
void StudentList::changeGrade(int grade)
{
}
