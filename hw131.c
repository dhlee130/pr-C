#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k;
	int x, y;
	int mat1[100][100] = {0};
	int mat2[100][100] = {0};

	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &y);
		fscanf(ip, "%d", &x);

		for(j=0; j<y; j++)
		{
			for(k=0; k<x; k++)
			{
				fscanf(ip, "%d", &mat1[k][j]);
			}
		}

		for(j=0; j<y; j++)
		{
			for(k=0; k<x; k++)
			{
				fscanf(ip, "%d", &mat2[k][j]);
			}
		}

		for(j=0; j<y; j++)
		{
			for(k=0; k<x; k++)
			{
				printf("%d ", mat1[k][j] + mat2[k][j]);
			}
			printf("\n");
		}
	}


	fclose(ip);
}