#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int a;
	int i, j, k, l, m, n,o;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);
	
	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &a);

		for(j=0; j<a/2;j++)
		{
			for(m = a/2; m>j; m--)
				printf("*");
			for(l = a/2; l <=a/2+2*j;l++)
				printf("+");
			for(k = a/2; k >j; k--)
				printf("*");
			printf("\n");
		}
		for(n=0; n<a;n++)
		{
			printf("+");
		}
		printf("\n");
		for(o=a/2; o>0; o--)
		{
			for(m = a/2; m>o-1; m--)
				printf("*");
			for(l = 0; l<2*o-1; l++)
				printf("+");
			for(k = a/2; k>o-1; k--)
				printf("*");
			
			printf("\n");
		}

	}
	fclose(ip);
}