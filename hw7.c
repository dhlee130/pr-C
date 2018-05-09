#include <stdio.h>
#include <stdlib.h>

int sum_number(int s, int t);

void main(void)
{
	FILE *ip;
	int i;
	int noca, start, end;
	

	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d %d", &start, &end);
		printf("%d\n", sum_number(start, end));
	}
	fclose(ip);
}

int sum_number(int s, int t)
{
	int i;
	int sum=0;

	for(i=s; i<=t; i++)
	{
		sum +=i;
	}
	return sum;
}