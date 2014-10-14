#pragma once
#include <string>
using namespace std;

class Volunteer
{
private:
	int first; //first perferred month
	int second;  //second preferred month
	int third;  //third preferred month
	string name;  //person's name
public:
	Volunteer(void);
	void setFirst(int first);
	void setSecond(int second);
	void setThird(int third);
	void setName(string Name);
	int getFirst();
	int getSecond();
	int getThird();
	string getName();
};

