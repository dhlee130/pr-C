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
		fscanf(ip, "%d", &a); //³ôÀÌ
		for(k=0; k<a; k++)
			{
				printf("+");
			}
		printf("\n");
		for(j=2; j<a; j++)
		{
			printf("I");
			if(j%2==0)
			{
				for(l=2; l<a; l++)
				{
					if(l%2==0)
					{
						printf("X");
					}
					else
					{
						printf("-");
					}
				}
			}
			else
			{
				for(l=2; l<a; l++)
				{
				if(l%2==0)
					{
						printf("-");
					}
					else
					{
						printf("X");
					}
				}
			}
			printf("I\n");
		}
		for(k=0; k<a; k++)
			{
				printf("+");
			}
		printf("\n");


	}
	


	fclose(ip);
}