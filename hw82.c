#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k;
	int arr[101];
	int num, score;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		for(k=0; k<=100; k++)
		{
			arr[k]=0;
		}
		fscanf(ip, "%d", &num);

		for(j=0; j<num; j++)
		{
			fscanf(ip, "%d", &score);
			arr[score] += 1;
		}

		for(k=0; k<=100; k++)
		{
			if(arr[k]>=1)
			{
				printf("%d %d ", k, arr[k]);
			}
		}
		printf("\n");
	}


	fclose(ip);
}