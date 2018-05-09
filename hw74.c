#include <stdio.h>
#include <stdlib.h>

int startday(int year, int month);

void main(void)
{
	int noca;
	int i, j, k, l, m;
	int year, month;
	int start;
	int a;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &year);
		fscanf(ip, "%d", &month);

		printf("%d %d\n", year, month);
		l=1;

		for(start=startday(year, month); start>0; start--)//Ã³À½ 0
		{
			printf("0 ");
		}

		
		
			if(month == 2)
			{
				if((year%4==0) && (year%100!=0) || (year%400==0)) //À±³â
				{
					j=29;
				}
				else
				{
					j=28;
				}
			}
			else if((month==1) || (month==3) || (month==5) || (month==7) || (month==8) || (month==10) || (month==12))
				j=31;
			else
				j=30;

			for(k=1; k<=j; k++)
			{
				printf("%d ", k);
				if((startday(year, month)+k)%7==0)
				{
					printf("\n");
				}
			}

			if(j+startday(year, month)<=35 && j+startday(year, month)>28)
			{
				a=35;
			}
			else if(j+startday(year, month)<=28)
			{
				a=28;
			}
			else
			{
				a=42;
			}
			
			for(k=0; k<a-j-startday(year, month); k++)
			{
				printf("0 ");
				if((j+startday(year, month)+k+1)%7==0)
				{
					printf("\n");
				}
			}
			
		


	}


	fclose(ip);
}

int startday(int year, int month)
{
	int day=5;

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
		return day%7;
}