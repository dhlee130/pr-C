#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i;
	unsigned int a;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%x", &a);

		printf("%d\n", a);
	}


	fclose(ip);
}