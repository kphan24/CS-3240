/**************************
    Patrick Heintz, Khoa Phan, Nathan Broberg
    Group 9
    Data Structures - Homework #2
    Johnson-Trotter Algorithm
*/



#include <iostream>

using namespace std;

void johnsonTrotter(int input, int *list);
void populateArray(int *list, int perms);
void printList(int *list, int size);
int getDigits();
const int SIZE = 25; // max  size of array

int main()
{
    int perms;
    int list[SIZE];

    perms = getDigits();
    //plug user input to populate the array with correct number of digits
    populateArray(list, perms);
    //run the Johnson-Trotter algorithm to print out every permutation
    johnsonTrotter(perms, list);
    
    return 0;
}

int getDigits()
{
    int perms;
    //get user input for the number of digits
    cout << "Enter the number of n factoral digits you wish to calculate(1-25):  ";
    cin >> perms;
    while(perms < 1 || perms > SIZE) //error check
    {
        cout << "Try again.  Enter an integer 1 to 25";
    }
    cout << endl;

    return perms;
}
/******************************************
/   Function that prints x number
/   of elements from an array
*/

void printList(int *list, int size)
{
    int i = 0;

    for(i = 0; i < size; ++i)
    {
        cout << list[i] << " ";
    }

    cout << endl;
    return;
}
/**********************************
/   Populate an array with ints
/   starting at 1 and ending with
/   user input value
/**********************************/

void populateArray(int *list, int perms)
{
    int i = 0;

    for(i = 0; i < perms; ++i)
    {
        list[i] = i + 1;
    }
    return;
}


/***************************************************
/   Johnson-Trotter algorithm printing all
/   permutations of a passed number of digits.
*/

void johnsonTrotter(int perms, int *list)
{

    //find total number of permutations using n factoral
    int nfactoral = 1;
    int temp;
    int i, k, j;
    //calculate the number of perms using factorals
    for (i = 0; i < perms; ++i)
    {
        nfactoral *= list[i];
    }
    //print the first iteration of the list
    cout << "There are " << nfactoral << " permutations\n\n";
    printList(list, perms);

    for(i=1; i < nfactoral; ++i)
    {
        //move last element one by one to first elm
        for(k = perms-1; k > 0 ; --k)
        {
            temp = list[k];
            list[k] = list[k-1];
            list[k-1] = temp;
            printList(list, perms);
            ++i;
        }
        //now swap last two elms
        if(i < nfactoral)
        {
            temp = list[perms-1];
            list[perms-1] = list[perms-2];
            list[perms-2] = temp;
            printList(list, perms);
            ++i;

        }

        //now move first to last
        for(j=0; j < perms-1 && i < nfactoral; ++j, ++i)
        {
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;
            printList(list, perms);
        }
        //now swap the first two elements
        if(i < nfactoral)
        {
            temp = list[0];
            list[0] = list[1];
            list[1] = temp;
            ++i;
        }

    }
    
    return;
}

/*  Test Run 1

    Enter the number of n factoral digits you wish to calculate(1-25):  2

There are 2 permutations

1 2
2 1

Process returned 0 (0x0)   execution time : 1.112 s
Press any key to continue.


    Test Run 2

Enter the number of n factoral digits you wish to calculate(1-25):  4

There are 24 permutations

1 2 3 4
1 2 4 3
1 4 2 3
4 1 2 3
4 1 3 2
1 4 3 2
1 3 4 2
1 3 2 4
3 1 4 2
3 4 1 2
4 3 1 2
4 3 2 1
3 4 2 1
3 2 4 1
3 2 1 4
2 3 4 1
2 4 3 1
4 2 3 1
4 2 1 3
2 4 1 3

Process returned 0 (0x0)   execution time : 2.775 s
Press any key to continue.


Test Run 3
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7
1 2 3 4 5 7 6
1 2 3 4 7 5 6
1 2 3 7 4 5 6
1 2 7 3 4 5 6
1 7 2 3 4 5 6
7 1 2 3 4 5 6
7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 6 5 7
2 1 3 4 6 7 5
2 1 3 4 7 6 5
2 1 3 7 4 6 5
2 1 7 3 4 6 5
2 7 1 3 4 6 5
7 2 1 3 4 6 5
7 2 1 3 4 5 6
2 7 1 3 4 5 6
2 1 7 3 4 5 6
2 1 3 7 4 5 6
2 1 3 4 7 5 6
2 1 3 4 5 7 6
2 1 3 4 5 6 7

Process returned 0 (0x0)   execution time : 5.481 s
Press any key to continue.


*/
