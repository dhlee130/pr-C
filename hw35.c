#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i;
	int a, b, c;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &a);
		fscanf(ip, "%d", &b);
		fscanf(ip, "%d", &c);

		if(c>=a && c<=b)
			printf("1\n");
		else
			printf("0\n");
	}


	fclose(ip);
}