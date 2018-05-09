#include <stdio.h>
#include <stdlib.h>

int isyear(int year);

void main(void)
{
	int noca;
	int i;
	int year;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &year);

		printf("%d\n", isyear(year));
	}


	fclose(ip);
}


int isyear(int year)
{
	return (year%4==0) && (year%100!=0) || (year%400==0);
}