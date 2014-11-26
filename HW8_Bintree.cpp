#include "Heintz_binTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct lineList
{
    int lineNum;
    LIST *next;
}LIST;

typedef struct nodeTag{
   char data[80];
   LIST *lines;
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
}

/******************************************
    Free memory from binary tree using
    recursion
*/
void destructTree(NODE *root)
{
    if(root)
    {
        destructTree((root)->left);
        destructTree((root)->right);
        destroyList(root->lines);
        free(root);
    }
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
void insert(NODE **root, char *data, int line)
{
    LIST *mover;
    if(!(*root)) //if no root exists
    {
        if(!(*root = (NODE *) malloc (sizeof(NODE))))
            printf( "Fatal malloc error!\n" ), exit(1);
        strcpy((*root)->data, data);
        (*root)->left  = (*root)->right = NULL;
        (*root)->lines = addToList();
        mover = (*root)->lines;
        mover->lineNum = line;
        return;
    }

    if (strcmp(data, (*root)->data) > 0)
        return insert(&(*root)->right, data, line);
    else if (strcmp(data, (*root)->data) < 0)
        return insert(&(*root)->left, data, line);
    else
    {
        mover = (*root)->lines;
        if(mover)
            while(mover->next)
                mover = mover->next;

        if(mover) // make sure you have at least one element in the queue
        {
            mover->next = addToList();  //allocate memory for new node
            mover->next->lineNum = line; //set data
        }
        else // if the queue is empty, then lines will return NULL and you
               //are inserting the first element
        {
            mover = addToList();
            mover->lineNum = line;
            (*root)->lines = mover;
        }
    }
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
void writeArray(char program[][80], FILE *fp, int lineNum)
{
    int line = 1;
    int i;


    for(i=0; i<lineNum; ++i)
    {
        fprintf(fp, "%2d :\t%s", line, program[i]);
        ++line;
    }
}
