#pragma once


struct NODE;

class StudentList
{
private:
	NODE listNode;

public:
	StudentList(void);
	~StudentList(void);
	NODE *findStudent(int ID);
	void recordGrade(int grade);
	void newSemester();
	void newStudent(int ID);
	void recordAssignment(int grade);
	void recordTest(int grade);
	void recordExam(int grade);
	void changeGrade(int grade);
};
