/*
    Patrick Heintz, Khoa Phan
    HW8 Keywords From Text
    CODE BLOCKS
    WIN 7 64 bit
*/


#include "HW8_BinTree_GR9.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

NODE *readFromFile(char *fileName, char pArray[][300], int *lineNum, int *grThree, int *totalWords, int *avLength, int *totalLen);
NODE *getID(char *line, char pArray[][300], int *lineNum, int *grThree, int *totalWords, int *numSentences, int *totalLen);
void displayTime(FILE *fp);
void writeStats(FILE *fp, int uniqueWords, int totalWords, int totalLen, int avLength, int grThree);

int main()
{
   NODE *root = NULL;
   char program[1000][300]; //to hold program's lines
   int lineNum=0;
   int grThree=0;//num of unique words greater than 3 characters
   int totalWords=0;
   int uniqueWords=0;
   int avLength=0; //average length of a sentence
   int wordLen=0; //total length of all words

   char fileName[30];
   printf("please input filename:   ");
   scanf("%s", fileName);
   printf("\n\n");

   root = readFromFile(fileName, program, &lineNum, &grThree, &totalWords, &avLength, &wordLen); //pass filename by argument
   if(!root)
    return 0; //if file not found, root will return null

   FILE *fp;
   fp = fopen("GR9_Output.txt", "w");
   displayTime(fp);     //write timestamp to file
   treeToFile(root, fp); //write tree to file with line nums
   destructTree(root, &uniqueWords); //frees allocated memory from tree AND queue

   writeStats(fp, uniqueWords, totalWords, wordLen, avLength, grThree);
   writeArray(program, fp, lineNum);

   fclose(fp);


   return 0;
}

void writeStats(FILE *fp, int uniqueWords, int totalWords, int totalLen, int avLength, int grThree)
{
    int avWordLen = (totalLen) / (totalWords);

    fprintf(fp, "\nNumber of unique words: %i\n", uniqueWords);
    fprintf(fp, "Number of total words: %i\n", totalWords);
    fprintf(fp, "Average Sentence Length: %i\n", avLength);
    fprintf(fp, "Average Word Length: %i\n", avWordLen);
    fprintf(fp, "Number of words greater than three: %i", grThree);
    fprintf(fp, "\n\n---------Style Warnings-----------\n\n");
    if(avWordLen > 5)
        fprintf(fp, "Average Word Length Greater Than 5\n");
    if(avLength > 10)
        fprintf(fp, "Average Sentence Length Greater Than 10\n");
    fprintf(fp, "\n\n\n");
    return;
}

/******************************************
    Function that timestamps a file
*/
void displayTime(FILE *fp)
{
    struct tm *timeptr;
    time_t timeval;
    char buffer[300];

    time(&timeval);

    timeptr = localtime(&timeval);
    strftime(buffer, 80, "%A, %B %d, %H:%M\n", timeptr);
    fprintf(fp, "--------------------------------\n %s\n", buffer);
}
/******************************************
    read from file using input from user
    get line by line and call to getID
    using line from input file to get keywords
*/
NODE *readFromFile(char *fileName, char pArray[][300], int *lineNum, int *grThree, int *totalWords, int *avLength, int *totalLen)
{
    NODE *root;
    FILE *fp;
    int numOfSentences = 0;
    char c;
    char line[300];
    if(!(fp = fopen(fileName, "r"))) //read from argument specified
    {
        printf("File not found. Shutting Down.");
        return NULL;
    }
    while(fgets(line, 300, fp))
    {
        root = getID(line, pArray, lineNum, grThree, totalWords, &numOfSentences, totalLen); //get line stats
        printf("%i sentences\n", numOfSentences);
        strcpy(line, "");
    }
    fclose(fp);
    *avLength = (*totalWords) / (numOfSentences);
    return root;
}


/******************************************
    Get keywords from line using
    a number of filters, then insert
    into BST. Static variable for root
    that is returned after entire file is read
    and stored into the BST
*/
NODE *getID(char *line, char pArray[][300], int *lineNum, int *grThree, int *totalWords, int *numSentences, int *totalLen)
{
    static NODE *root;
    int i = 0;
    int j = 0;
    int k = 0;
    int length;
    char keyword[300] = "";

    length = strlen(line);
    ++*lineNum;
    printf("copying line %d\n", *lineNum-1);
    strcpy(pArray[*lineNum-1], line);
    printf("copied\n");

    while(i < length)
    {
        while((isspace(line[i])) && i < length)
        {
            ++i; //check string for spaces
        }
        while(!(isalpha(line[i])) && i < length) //checking for non alphabetical characters
        {
            ++i;
        }
        j=0;
        while(isalpha(line[i]) && i < length)
        {
            keyword[j] = line[i];
            ++i;
            ++j;
            if(line[i] == '.')
            {
                *numSentences += 1;
            }
        }
        if(isalpha(keyword[0]))
        {
             for(k=0; k < strlen(keyword); ++k)
                keyword[k] = tolower(keyword[k]);
             insert(&root, keyword, *lineNum, grThree);  //insert into binary tree
             *totalLen += strlen(keyword);
             memset(keyword, 0, 80);
             ++i;
             ++*totalWords;
             printf("num of total words: %i\n", *totalWords);
        }
    }
    return root; //return the whole way
}
