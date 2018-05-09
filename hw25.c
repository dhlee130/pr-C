#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k;
	int a;
	int num;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &a);

		for(j=1; j<=a; j++)
		{
			num = j;

			for(k=0; k<j; k++)
			{
				printf("%d ", num);

				num = num + a -(k+1);
			}
			printf("\n");
		}
	}


	fclose(ip);
}