#include "MyStack.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

MyStack::MyStack()
{
	size = 0;
}

MyStack::~MyStack()
{
    NODE *current;
    NODE *prev;
    if(topStack)
    {
        current = topStack;
        while(size > 0)
        {
            pop();
            --size;
        }
    }
}

int MyStack::getSize()
{
    return size;
}

/*
    take one element off the stack, delete it
    and return the value
*/
string MyStack::pop()
{
    string returnVal;
    NODE *current;
    NODE *temp;

    if(size > 0)
	{
	    current = topStack;
		returnVal = current->data; //get data from node
		if(size > 1)
		{
			temp = current->previous;
			topStack = temp;
		}
		delete current;
		--size;
		cout << "popping " << returnVal << endl;
		return returnVal; //return data
	}
    else if (size <= 0)
	{
	    size = 0;
        cout << "stack empty\n";
        return " ";
	}

}

/*
    Allocate memory for a new node
    and put it onto the stack
*/
void MyStack::push(string data)
{
    cout << "pushing " << data << endl;
    NODE *newNode;
    newNode = new NODE;
    newNode->data = data;
    if(size == 0)
        topStack = newNode;  //head points to new node
	else if(size > 0)
    {
        newNode->previous = topStack;  //point new previous to old head
        topStack = newNode;  //point head pointer to new head
    }
	++size;
	return;
}
