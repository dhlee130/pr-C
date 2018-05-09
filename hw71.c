#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j;
	int year, day, month, date;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &year);
		fscanf(ip, "%d", &month);
		fscanf(ip, "%d", &date);
		day = 5;

		for(;date>1;date--)
		{
			day++;
		}

		month--;
		for(;month>=1;month--)
		{
			if(month == 2)
			{
				if((year%4==0) && (year%100!=0) || (year%400==0))
				{
					day++;
				}
			}
			else if((month==1) || (month==3) || (month==5) || (month==7) || (month==8) || (month==10) || (month==12))
			{
				day +=3;
			}
			else
			{
				day +=2;
			}
		}
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