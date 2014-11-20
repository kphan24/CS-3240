#include "MatrixStructure.h"
#include <iostream>
#include <string>

using namespace std;

MatrixStructure::MatrixStructure()
{
	size = 0;
	firstRow = new NODE;
	firstRow->next = NULL;
	firstRow->previous = NULL;
	firstRow->col = NULL;
}

MatrixStructure::~MatrixStructure()
{
    NODE *current;
}

int MatrixStructure::getSize()
{
    return size;
}

/*
    take one element off the stack, delete it
    and return the value
*/

void getCol(NODE *row, ofstream &stream)
{
    COLUMN *col;
    if(row->col)
        col = row->col;
    else
        return 0;
    while(col->next)
    {
        stream << col->data;
        col = col->next;
    }
    return;
}
void MatrixStructure::writeMatrix(ofstream &oFile, NODE *current, int currentRow)
{
    COLUMN *col;

    if(currentRow == current->rowNum && size > currentRow)
    {
        getCol(current, oFile);
    }
    else
    {
       int i;
       for(i=0; i<width; ++i)
       {
           oFile << 0
       }
    }
    if(current->next) //if next exists
    {
        writeMatrix(oFile, current->next, currentRow+1);
    }
    return;

}
void MatrixStructure::readMatrix(int row, int value, int column, NODE *current)
{
    if (value == 0)
        return;

    if(!firstRow)
    {
        NODE *newNode;
        newNode = new NODE;  //if list does not exist
        newNode->rowNum = row;
        firstRow = newNode;
    }
    if(row == current->rowNum)
    {
        insertCol(current, row, value); //if row is equal to current node
                                        //insert the col by calling insertCol
    }
    else if(row > current)
    {
        if(current->next) //if next node exists
        {
            current = current->next; //move to next node
            readMatrix(row, value, column, current);  //call readMatrix with the 'new' current
        }
        else
        {
            NODE *newNode; //if next does not exist, new node must be the next node
            newNode = new NODE;
            newNode->rowNum = row;
            current->next = newNode;
            newNode->previous = current;
            return;
        }
    }
    else if(row < current)
    {
        NODE *newNode;
        newNode = new NODE;
        newNode->rowNum = row;
        newNode->next = current; //since newnode is less than current
        newNode->previous = current->previous; //putting new node 'in between'
        current = current->previous; //setting old previous to point 'next' to
        current->next = newNode;     //the new node
        return;
    }
}
