#include "MatrixStructure.h"
#include <iostream>
#include <string>

using namespace std;

void menu(MatrixStructure matrix);
void readFromFile(string fileName);
//need read in and read out functions, these functions pass to functions
//in the class cpp file which should correctly place the values in the list

int main()
{
    MatrixStructure *matrix;
    matrix = new MatrixStructure;
}
