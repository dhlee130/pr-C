#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100

void inputnums(FILE *inFile);
int comparenums(const void *a, const void *b);
void printnums();

int intnums;
int *ints[MAX_NUM];

void main()
{
	FILE *inFile;
	int numtestcases;

	

	inFile = fopen("input.txt", "r");
	if(inFile == NULL) exit(1);

	fscanf(inFile, "%d", &numtestcases);

	while(numtestcases--)
	{
		int i;

		inputnums(inFile);
		qsort(ints, intnums, sizeof(int *), comparenums);
		printnums();

		
	}
	fclose(inFile);
}

void inputnums(FILE *inFile)
{
	int i;
	
	fscanf(inFile, "%d", &intnums);

	for(i=0; i<intnums; i++)
	{
		fscanf(inFile, "%d", &ints[i]);
	}
}

int comparenums(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void printnums()
{
	int i;

	for(i=0; i<intnums; i++)
	{
		printf("%d ", ints[i]);
	}
	printf("\n");
}
