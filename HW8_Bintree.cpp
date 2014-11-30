/*
    Patrick Heintz, Khoa Phan
    HW8 Keywords From Text
    CODE BLOCKS
    WIN 7 64 bit
*/

#include "HW8_BinTree_GR9.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//  each node in the binary tree contains a queue
//  that stores the number of times a unique word occurs
//  as well as the line number it occurs on
typedef struct lineList
{
    int lineNum;
    LIST *next;
}LIST;

typedef struct nodeTag{
   char data[80];
   LIST *lines;
   int numWords;
   struct nodeTag *left;
   struct nodeTag *right;
} NODE;

/******************************************
    Free memory from queue
*/
void destroyList(LIST *myList)
{
    LIST *current;
    LIST *next;
    current = myList;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    return;
}

/******************************************
    Free memory from binary tree using
    recursion
*/
void destructTree(NODE *root, int *uniqueWords)
{
    if(root)
    {
        destructTree((root)->left, uniqueWords);
        destructTree((root)->right, uniqueWords);
        destroyList(root->lines);
        ++*uniqueWords;
        free(root);
    }
    return;
}

/****************************************************************
   INORDER
   Print a BST in Left-Root-Right sequence.
*/
void treeToFile(NODE *root, FILE *fp)
{
    if(root)
    {
        treeToFile(root->left, fp);
        fprintf(fp, "%-15s",  root);
        printList(root->lines, fp);
        fprintf(fp, "\n");
        treeToFile(root->right, fp);
    }
    return;
}


/******************************************
    Recursive insert for BST and queue attached
    to the BST nodes
*/
void insert(NODE **root, char *data, int line, int *grThree)
{
    LIST *mover;
    if(!(*root)) //if no root exists
    {
        if(!(*root = (NODE *) malloc (sizeof(NODE))))
            printf( "Fatal malloc error!\n" ), exit(1); //memory check
        strcpy((*root)->data, data);  //if no list, allocate data to the root
        (*root)->left  = (*root)->right = NULL;
        (*root)->lines = addToList(); //allocates memory to be pointed to
        mover = (*root)->lines;
        mover->lineNum = line;
        if(strlen(data)>3)
            ++*grThree;  //when inserting node if word is greater than 3 chars increment
        return;
    }

    if (strcmp(data, (*root)->data) > 0) //compare and allocate accordingly using recursion
    {
        insert(&(*root)->right, data, line, grThree);
    }
    else if (strcmp(data, (*root)->data) < 0)
    {
        insert(&(*root)->left, data, line, grThree);
    }
    else //node already exists, put in queue
    {
        mover = (*root)->lines;
        if(mover)
            while(mover->next)
                mover = mover->next;

        if(mover) // make sure you have at least one element in the queue
        {
            mover->next = addToList();  //allocate memory for new node
            mover->next->lineNum = line; //set data
            (*root)->numWords++;
        }
        else // if the queue is empty, then lines will return NULL and you
               //are inserting the first element
        {
            mover = addToList();
            mover->lineNum = line;
            (*root)->lines = mover;
            (*root)->numWords = 1;
        }
    }
	return;
}

/******************************************
    Allocate memory for queue node
    then return it
*/
LIST *addToList()
{
    LIST *pnew;
    pnew = (LIST *) malloc(sizeof (LIST)); //memory for LIST
    if (!pnew)
    {
        printf("Fatal memory allocation error in insert!\n");
        exit(3);
    }
    pnew->next = NULL; //set next node to NULL

    return pnew;
}

/******************************************
    Prints a queue to a file
*/
void printList(LIST *myList, FILE *fp)
{
    LIST *mover;
    mover = myList;
    while(mover) //while mover
    {
        fprintf(fp, "%5d", mover->lineNum); //line nums where string occurs
        mover = mover->next; //move to next node
    }
}

/******************************************
    Writes a string array to file using
    a number of lines
*/
void writeArray(char program[][300], FILE *fp, int lineNum)
{
    int line = 1;
    int i;


    for(i=0; i<lineNum; ++i)
    {
        fprintf(fp, "%2d :\t%s", line, program[i]); //print listing
        ++line;
    }
}
