#ifndef HEINTZ_BINTREE_H_INCLUDED
#define HEINTZ_BINTREE_H_INCLUDED
#include <stdio.h>

typedef struct lineList LIST;
typedef struct nodeTag NODE;

void treeToFile(NODE *root, FILE *fp);
void destroyList(LIST *myList);
void insert(NODE **root, char *data, int line);
LIST *addToList();
void destructTree(NODE *root);
void printList(LIST *myList, FILE *fp);
void printTreeInorder(NODE *root);
NODE *allocateNode(char *data, int line);
void writeArray(char program[][80], FILE *fp, int lineNum);

#endif
