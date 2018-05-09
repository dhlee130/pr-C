#include <stdio.h>
#include <stdlib.h>

int **addmatrix(int **a, int **b, int row, int col);
void readmatrix(FILE *inFile, int **m, int row, int col);
void printmatrix(int **m, int row, int col);
int **getmatrix(int row, int col);
void freematrix(int **m);

void main(void)
{
	FILE *inFile;
	int numtest;

	inFile = fopen("input.txt", "r");
	if(inFile == NULL) exit(1);

	fscanf(inFile, "%d", &numtest);

	while(numtest--)
	{
		int **a, **b, **c;
		int row, col;

		fscanf(inFile, "%d %d", &row, &col);

		a = getmatrix(row, col);
		b = getmatrix(row, col);

		readmatrix(inFile, a, row, col);
		readmatrix(inFile, b, row, col);

		c = addmatrix(a, b, row, col);
		
		printmatrix(c, row, col);
		
		freematrix(a);
		freematrix(b);
		freematrix(c);
	}

	fclose(inFile);
}

int **addmatrix(int **a, int**b, int row, int col)
{
	int i, j;
	int **c;
	int *aptr, *bptr, *cptr;

	c = getmatrix(row, col);

	for(i=0; i<row; i++)
	{
		aptr = *(a+i);
		bptr = *(b+i);
		cptr = *(c+i);

		for(j=0; j<col; j++)
			*cptr++ = *aptr++ + *bptr++;
	}

	return c;
}

void readmatrix(FILE *inFile, int **m, int row, int col)
{
	int i, j;
	int *rowptr;

	for(i=0; i<row; i++)
	{
		rowptr = *(m+i);
		for(j=0; j<col; j++)
			fscanf(inFile, "%d", rowptr++);
	}
}

void printmatrix(int **m, int row, int col)
{
	int i, j;
	int *rowptr;

	for(i=0; i<row; i++)
	{
		rowptr = *(m+i);
		for(j=0; j<col; j++)
			printf("%d ", *rowptr++);
		printf("\n");
	}
}

int **getmatrix(int row, int col)
{
	int i;
	int **matrix;
	int *m;

	matrix = (int **) malloc(sizeof(int *) * row);
	m = (int *) malloc(sizeof(int) * row * col);

	if(matrix == NULL || m == NULL)
	{
		exit(1);
	}

	for(i=0; i<row; i++)
	{
		*(matrix+i) = m;
		m += col;
	}

	return matrix;
}

void freematrix(int **m)
{
	free (*m);
	free(m);
}
