/*
    Patrick Heintz
    HW5 KEYWORDS FROM C FILE
    CODE BLOCKS
    WIN 7 64 bit
*/


#include "Heintz_binTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


NODE *readFromFile(char *fileName, char pArray[][80], int *lineNum);
NODE *getID(char *line, char pArray[][80], int *lineNum);
void displayTime(FILE *fp);

int main(int argc, char *argv[])
{
   NODE *root = NULL;
   char program[1000][80]; //to hold program's lines
   int lineNum=0;

   root = readFromFile(argv[1], program, &lineNum); //pass filename by argument

   FILE *fp;
   fp = fopen("heintz_output.txt", "w");
   displayTime(fp);     //write timestamp to file
   treeToFile(root, fp); //write tree to file with line nums
   destructTree(root); //frees allocated memory from tree AND queue

   writeArray(program, fp, lineNum);
   fclose(fp);


   return 0;
}

/******************************************
    Function that timestamps a file
*/
void displayTime(FILE *fp)
{
    struct tm *timeptr;
    time_t timeval;
    char buffer[80];

    time(&timeval);

    timeptr = localtime(&timeval);
    strftime(buffer, 80, "%A, %B %d, %H:%M\n", timeptr);
    fprintf(fp, "--------------------------------\n %s\n", buffer);
}
/******************************************
    read from file using input from argv
    get line by line and call to getID
    using line from input file to get keywords
*/
NODE *readFromFile(char *fileName, char pArray[][80], int *lineNum)
{
    NODE *root;
    FILE *fp;
    char c;
    char line[81];
    if(!(fp = fopen(fileName, "r"))) //read from argument specified
    {
        printf("File not found. Shutting Down.");
        return;
    }
    while(fgets(line, 81, fp))
    {
        root = getID(line, pArray, lineNum); //call to get keywords from line
        //printf("%s\n", line);
        strcpy(line, "");
    }
    fclose(fp);
    return root;
}


/******************************************
    Get keywords from lines of code using
    a number of filters, then insert
    into BST. Static variable for root
    that is returned after entire file is read
    and stored into the BST
*/
NODE *getID(char *line, char pArray[][80], int *lineNum)
{
    static NODE *root;
    static int comment = 0;
    int i = 0;
    int j = 0;
    int length;
    char keyword[80] = "";

    length = strlen(line);
    ++*lineNum;
    printf("copying line %d\n", *lineNum-1);
    strcpy(pArray[*lineNum-1], line);
    printf("copied\n");

    while(i < length)
    {
        while((isspace(line[i])) && comment == 0 && i < length)
            ++i;
        while(!(isalpha(line[i])) && comment == 0 && i < length)
        {
            if(line[i] == '/' && (line[i+1]) == '/')
                return;
            if(line[i] == '/' && (line[i+1]) == '*') //check for comment
                comment = 1;
            if (line[i] == '#')  //check for define
                return;
            if (line[i] == '\"')//check for quotes
            {
                ++i;
                while(line[i] != '\"' && i < length)
                    ++i;
            }
            ++i;
        }
        while(comment == 1 && i < length)
        {
            if(line[i] == '*' && (line[i+1]) == '/')
                comment = 0;
            else
                ++i;
        }

        j=0;
        while(isalpha(line[i]) && comment == 0 && i < length)
        {
            keyword[j] = line[i];
            keyword[j];
            ++i;
            ++j;
        }
        if(isalpha(keyword[0]))
        {
            //printf("inserting word %s\n", keyword)
             insert(&root, keyword, *lineNum);  //insert into binary tree

        memset(keyword, 0, 80);
        ++i;
        }
    }
    return root; //return the whole way
}

/*
--------------------------------
 Monday, June 23, 22:40

FILE              48  119  130
LIST              11   12   16   21   23   24   65  105  107  108  108  119  121
NODE              19   33   48   63   68   68
NULL              26   71  114
addToList         72   92   98  105
char              15   63  130
current           23   25   26   28   29   30
data              15   63   70   70   78   78   79   80   80   81
destroyList       21   39
destructTree      33   37   38
else              80   82   95
exit              69  112
for              136
fp                48   52   53   54   55   56  119  125  130  138
fprintf           53   55  125  138
free              29   40
i                133  136  136  136  138
if                35   50   66   68   78   80   86   90  109
insert            63   79   81
int               10   63  130  132  133
left              17   37   52   71   81
line              63   74   79   81   93   99  132  138  139
lineList           8
lineNum           10   74   93   99  125  130  136
lines             16   39   54   72   73   84  100
malloc            68  108
mover             65   73   74   84   86   87   88   88   90   92   93   98   99  100  121  122  123  125  126  126
myList            21   25  119  122
next              11   24   28   28   30   87   88   92   93  114  126
nodeTag           14   17   18
pnew             107  108  109  114  116
printList         54  119
printf            69   85  111
program          130  138
return            58   75   79   81  116
right             18   38   56   71   79
root              33   35   37   38   39   40   48   50   52   53   54   56   63   66   68   70   71   71   72   73   78   79   80   81   84  100
sizeof            68  108
strcmp            78   80
strcpy            70
struct             8   14   17   18
treeToFile        48   52   56
typedef            8   14
void              21   33   48   63  119  130
while             26   87  123
writeArray       130
 1 :	#include "Heintz_binTree.h"
 2 :	#include <stdio.h>
 3 :	#include <stdlib.h>
 4 :	#include <time.h>
 5 :	#include <string.h>
 6 :
 7 :
 8 :	typedef struct lineList
 9 :	{
10 :	    int lineNum;
11 :	    LIST *next;
12 :	}LIST;
13 :
14 :	typedef struct nodeTag{
15 :	   char data[80];
16 :	   LIST *lines;
17 :	   struct nodeTag *left;
18 :	   struct nodeTag *right;
19 :	} NODE;
20 :
21 :	void destroyList(LIST *myList)
22 :	{
23 :	    LIST *current;
24 :	    LIST *next;
25 :	    current = myList;
26 :	    while(current != NULL)
27 :	    {
28 :	        next = current->next;
29 :	        free(current);
30 :	        current = next;
31 :	    }
32 :	}
33 :	void destructTree(NODE *root)
34 :	{
35 :	    if(root)
36 :	    {
37 :	        destructTree((root)->left);
38 :	        destructTree((root)->right);
39 :	        destroyList(root->lines);
40 :	        free(root);
41 :	    }
42 :	}
43 :
44 :	/****************************************************************
45 :	   INORDER
46 :	   Print a BST in Left-Root-Right sequence.
47 :
48 :	void treeToFile(NODE *root, FILE *fp)
49 :	{
50 :	    if(root)
51 :	    {
52 :	        treeToFile(root->left, fp);
53 :	        fprintf(fp, "%-15s",  root);
54 :	        printList(root->lines, fp);
55 :	        fprintf(fp, "\n");
56 :	        treeToFile(root->right, fp);
57 :	    }
58 :	    return;
59 :	}
60 :
61 :	//   RECURSIVE Insert
62 :
63 :	void insert(NODE **root, char *data, int line)
64 :	{
65 :	    LIST *mover;
66 :	    if(!(*root)) //if no root exists
67 :	    {
68 :	        if(!(*root = (NODE *) malloc (sizeof(NODE))))
69 :	            printf( "Fatal malloc error!\n" ), exit(1);
70 :	        strcpy((*root)->data, data);
71 :	        (*root)->left  = (*root)->right = NULL;
72 :	        (*root)->lines = addToList();
73 :	        mover = (*root)->lines;
74 :	        mover->lineNum = line;
75 :	        return;
76 :	    }
77 :
78 :	    if (strcmp(data, (*root)->data) > 0)
79 :	        return insert(&(*root)->right, data, line);
80 :	    else if (strcmp(data, (*root)->data) < 0)
81 :	        return insert(&(*root)->left, data, line);
82 :	    else
83 :	    {
84 :	        mover = (*root)->lines;
85 :	        printf("Node already in the tree!\n");
86 :	        if(mover)
87 :	            while(mover->next)
88 :	                mover = mover->next;
89 :
90 :	        if(mover) // make sure you have at least one element in the queue
91 :	        {
92 :	            mover->next = addToList();  //allocate memory for new node
93 :	            mover->next->lineNum = line; //set data
94 :	        }
95 :	        else // if the queue is empty, then lines will return NULL and you
96 :	               //are inserting the first element
97 :	        {
98 :	            mover = addToList();
99 :	            mover->lineNum = line;
100 :	            (*root)->lines = mover;
101 :	        }
102 :	    }
103 :	}
104 :
105 :	LIST *addToList()
106 :	{
107 :	    LIST *pnew;
108 :	    pnew = (LIST *) malloc(sizeof (LIST)); //memory for LIST
109 :	    if (!pnew)
110 :	    {
111 :	        printf("Fatal memory allocation error in insert!\n");
112 :	        exit(3);
113 :	    }
114 :	    pnew->next = NULL; //set next node to NULL
115 :
116 :	    return pnew;
117 :	}
118 :
119 :	void printList(LIST *myList, FILE *fp)
120 :	{
121 :	    LIST *mover;
122 :	    mover = myList;
123 :	    while(mover) //while mover
124 :	    {
125 :	        fprintf(fp, "%5d", mover->lineNum); //line nums where string occurs
126 :	        mover = mover->next; //move to next node
127 :	    }
128 :	}
129 :
130 :	void writeArray(char program[][80], FILE *fp, int lineNum)
131 :	{
132 :	    int line = 1;
133 :	    int i;
134 :
135 :
136 :	    for(i=0; i<lineNum; ++i)
137 :	    {
138 :	        fprintf(fp, "%2d :\t%s", line, program[i]);
139 :	        ++line;
140 :	    }
141 :	}
*/
