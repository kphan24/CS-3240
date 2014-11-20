#ifndef MATRIXSTRUCTURE_H
#define MATRIXSTRUCTURE_H

#include <iostream>
#include <string>
using namespace std;

struct COLUMN
{
    int columnNum;
    int data;
    COLUMN *previous;
    COLUMN *next;
};
struct NODE
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
        int depth;
		int size;
        NODE *firstRow;
};

#endif MATRIXSTRUCTURE_H
