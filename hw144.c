#include <stdio.h>
#include <stdlib.h>

int *inputdata(FILE *inFile, int *size);
void computerun(int *data, int size);

void main(void)
{
	FILE *inFile;
	int numtest;

	inFile = fopen("input.txt", "r");
	if(inFile == NULL) exit(1);
	
	fscanf(inFile, "%d", &numtest);

	while(numtest--)
	{
		int size;
		int *data;
		

		data = inputdata(inFile, &size);
		computerun(data, size);
		free(data);
	}

	fclose(inFile);
}

int *inputdata(FILE *inFile, int *size)
{
	int *data;
	
	int i;

	fscanf(inFile, "%d", size);
	data = (int *)malloc(sizeof(int) * *size);
	if(data == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}

	for(i=0; i<*size; i++)
	{
		
		fscanf(inFile, "%d", data+i);
	}

	return data;
}

void computerun(int *data, int size)
{
	int i;
	int a;
	int count = 1;

	for(i=0; i<size; i++)
	{
		a = *data;
		count = 1;
		while(a == *++data)
		{
			count++;
			i++;
		}
		printf("%d %d ", a, count);
	}
	printf("\n");
}