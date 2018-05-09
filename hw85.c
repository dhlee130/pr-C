#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca, num;
	int i, j, k, l;
	int x[256] = {0};
	int y[256] = {0};
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &num);

		for(j=0; j<num; j++)
		{
			fscanf(ip, "%d", &x[j]);
		}

		fscanf(ip, "%d", &k);

		for(j=0; j<num-k+1; j++)
		{
			for(l=0; l<k; l++)
			{
				y[j] += x[j+l];
			}
			y[j] /= k;
		}

		printf("%d ", num-k+1);

		for(j=0; j<num-k+1; j++)
		{
			printf("%d ", y[j]);
		}

		printf("\n");

		for(j=0; j<num-k+1; j++)
		{
			y[j] = 0;
		}

	}


	fclose(ip);
}