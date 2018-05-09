#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *ip;
	int noca, noda;
	int i, j;
	int a, total;

	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		total = 1;
		fscanf(ip, "%d", &noda);

		for(j=0; j<noda; j++)
		{
			fscanf(ip, "%d", &a);

			total *= (a%100);
			total = total%100;
		}
		printf("%d\n", total);
	}


	fclose(ip);
}