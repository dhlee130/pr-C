#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k, l, m, n, o;
	int a;     //Ãþ

	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &a);
		for(k=0; k<a; k++)
		{
			if(k%2==0)
			{
				printf("*");
			}
			else
			{
				printf("+");
			}
		}
		printf("\n");
		for(j=a/2; j>0; j--)  //À§ÂÊ 
		{
			for(l=0; l<a/2-j+1; l++)
			{
				printf("-");
			}
			for(m=0; m<2*j-1; m++)
			{
				if(m%2==0)
				{
					printf("*");
				}
				else
				{
					printf("+");
				}
			}
			for(l=0; l<a/2-j+1; l++)
			{	
				printf("-");
			}
			printf("\n");
		}

		for(o=0; o<a/2-1; o++)
		{
			for(l=1; l<a/2-o; l++)
			{
				printf("-");
			}
			for(m=0; m<2*(o+1)+1; m++)
			{
				if(m%2==0)
				{
					printf("*");
				}
				else
				{
					printf("+");
				}
			}
			for(l=1; l<a/2-o; l++)
			{
				printf("-");
			}
			printf("\n");
		}
		
		for(k=0; k<a; k++)
		{
			if(k%2==0)
			{
				printf("*");
			}
			else
			{
				printf("+");
			}
		}
		printf("\n");

	}





}