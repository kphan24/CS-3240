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
    NODE *current;  //need to go through each row and each col
    		    //and delete
}

int MatrixStructure::getSize()
{
    return size;
}

/*
	Get column from the data structure
	and output it to a file using the passed stream
*/
void getCol(NODE *row, ofstream &stream)
{
    COLUMN *col;
    if(row->col)  //col != NULL
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
/*
	Write matrix to file using the passed ofstream
	(passed from main where file is opened)
*/
void MatrixStructure::writeMatrix(ofstream &oFile, NODE *current, int currentRow) //need to pass a 0 for currentrow param
{
    COLUMN *col;

    if(depth > currentRow->rowNum) //print as long as depth is greater
    				   //than the # of rows
    {
        getCol(current, oFile);  //for each row, get each column
    }
    else
    {
       int i;
       for(i=0; i<width; ++i)  //if row is empty print zeroes
       {
           oFile << 0
       }
    }
    if(current->next) //if next exists
    {
        writeMatrix(oFile, current->next, currentRow+1); //if next exists, call through recursion
    }
    return;

}

/*
	read into matrix from passed values in main
	(main reads from file then passes values)
*/
void MatrixStructure::readMatrix(int row, int value, int column, NODE *current)
{
    if (value == 0)  //if the value is 0 then don't do anything
        return;

    if(!firstRow)  //if there is no pointer to the head of the list create one
    {
        NODE *newNode;
        newNode = new NODE;  //if list does not exist
        newNode->rowNum = row;
        firstRow = newNode;
    }
    if(row == current->rowNum)  //if row number already exists get new column
    {
        insertCol(current, row, column, value); //if row is equal to current node
                                        //insert the col by calling insertCol
    }
    else if(row > current->row)  //either there are more rows or hte adt needs a new row at the end
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
    else if(row < current->row) //insert node in between
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
