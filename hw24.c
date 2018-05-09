#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k;
	int a, b;
	int num1;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &a);
		fscanf(ip, "%d", &b);

		for(j=1; j<=b; j++)
		{
			num1 = j;
			for(k=0; k<a; k++)
			{
				printf("%d ", num1);
				num1 = num1 + b;
			}
			printf("\n");
		}
	}


	fclose(ip);
}