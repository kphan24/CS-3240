#ifndef MATRIXSTRUCTURE_H
#define MATRIXSTRUCTURE_H

#include <iostream>
#include <string>
using namespace std;

struct COLUMN  //columns are stored within the rows as another linked list
{  	
    int columnNum;
    int data;
    COLUMN *previous;
    COLUMN *next;
};
struct NODE  //NODE is actually a node in a linked list that represents a row
{
    int rowNum;
    NODE *previous;
    NODE *next;
    COLUMN *col;
};

class MatrixStructure
{
    public:
        MatrixStructure();
        ~MatrixStructure();
        void insert(int data, int row, int column);
        int getSize();
        void writeMatrix(ofstream &oFile, NODE *current, int currentRow);
        void readMatrix(int row, int value, int column, NODE *current);
    private:
        int width;
        int depth; //need get width and get depth functions
	int size;
        NODE *firstRow;
};

#endif MATRIXSTRUCTURE_H
