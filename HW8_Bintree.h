/*
    Patrick Heintz, Khoa Phan
    HW8 Keywords From Text
    CODE BLOCKS
    WIN 7 64 bit
*/

#ifndef HW8_BinTree_GR9_H_INCLUDED
#define HW8_BinTree_GR9_H_INCLUDED
#include <stdio.h>

typedef struct lineList LIST;
typedef struct nodeTag NODE;

void treeToFile(NODE *root, FILE *fp);
void destroyList(LIST *myList);
void insert(NODE **root, char *data, int line, int *grThree);
LIST *addToList();
void destructTree(NODE *root, int *uniqueWords);
void printList(LIST *myList, FILE *fp);
void printTreeInorder(NODE *root);
NODE *allocateNode(char *data, int line);
void writeArray(char program[][300], FILE *fp, int lineNum);

#endif
