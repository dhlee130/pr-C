#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k, l;
	int a;

	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &a);
		printf("*\n");
		printf("**\n");
		for(j=3; j<a; j++)
		{
			printf("*");
			for(k=2; k<j; k++)
			printf("+");
			printf("*\n");
		}
		for(l=0; l<a; l++)
		{
			printf("*");
		}
		printf("\n");
	}


	fclose(ip);

}