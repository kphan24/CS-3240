#ifndef Volunteer_h
#define Volunteer_h
#include <string>
using namespace std;

class Volunteer
{
private:
	int first; //first perferred month
	int second;  //second preferred month
	int third;  //third preferred month
	string name;  //person's name
	int assigned; //assigned month
public:
	Volunteer(void);
	void setFirst(int f);
	void setSecond(int s);
	void setThird(int t);
	void setName(string n);
	void setAssigned(int a);
	int getAssigned();
	int getFirst();
	int getSecond();
	int getThird();
	string getName();
};

#endif
