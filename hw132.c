#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k, l;
	int r, s, t;
	int mat1[100][100] = {0};
	int mat2[100][100] = {0};
	int mat3[100][100] = {0};

	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &r);
		fscanf(ip, "%d", &s);
		fscanf(ip, "%d", &t);

		for(j=0; j<r; j++)
		{
			for(k=0; k<s; k++)
			{
				fscanf(ip, "%d", &mat1[k][j]);
			}
		}

		for(j=0; j<s; j++)
		{
			for(k=0; k<t; k++)
			{
				fscanf(ip, "%d", &mat2[k][j]);
			}
		}

		

		for(j=0; j<r; j++)
		{
			for(k=0; k<t; k++)
			{
				for(l=0; l<s; l++)
				{
					mat3[k][j] += mat1[l][j] * mat2[k][l];
				}
			}
		}

		for(j=0; j<r; j++)
		{
			for(k=0; k<t; k++)
			{
				printf("%d ", mat3[k][j]);
			}
			printf("\n");
		}

		for(j=0; j<r; j++)
		{
			for(k=0; k<t; k++)
			{
				mat3[k][j] = 0;
			}
			
		}
	}


	fclose(ip);
}