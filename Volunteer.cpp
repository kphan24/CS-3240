#include "Volunteer.h"
#include <string>


Volunteer::Volunteer(void)
{
}

void Volunteer::setFirst(int f)
{
	first = f;
}
void Volunteer::setSecond(int s)
{
	second = s;
}
void Volunteer::setThird(int t)
{
	third = t;
}
void Volunteer::setName(string n)
{
	name = n;
}

void Volunteer::setAssigned(int a)
{
    assigned = a;
}
int Volunteer::getAssigned()
{
    return assigned;
}
int Volunteer::getFirst()
{
	return first;
}
int Volunteer::getSecond()
{
	return second;
}
int Volunteer::getThird()
{
	return third;
}
string Volunteer::getName()
{
	return name;
}
