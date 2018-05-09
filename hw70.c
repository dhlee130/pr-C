#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j;
	int year, day;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &year);
		day = 5;

		for(;year>1582;year--)
		{
			if(((year-1)%4==0) && ((year-1)%100!=0) || ((year-1)%400==0))
			{
				day += 2;
			}
			else
			{
				day++;
			}
			
		}
		printf("%d\n", day%7);

	}


	fclose(ip);
}