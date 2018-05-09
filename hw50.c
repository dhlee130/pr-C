#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		int value;
		int divisor;
		int num = 1;
		int sum = 1;

		fscanf(ip, "%d", &value);

		for(divisor=2; divisor*divisor<=value; divisor++)
		{
			if(value%divisor == 0)
			{
				num=num+2;
				sum=sum+divisor+(value/divisor);
			}
			
		}
		printf("%d %d\n", num , sum);
	}


	fclose(ip);
}