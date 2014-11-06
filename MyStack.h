#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct NODE
{
    string data;
    NODE *previous;
};

class MyStack
{
    public:
        MyStack();
        ~MyStack();
        void push(string data);
        string pop();
        NODE *topStack;
        int getSize();
    private:
		int size;
};

#endif // MYSTACK_H
