#include <stdio.h>
#include <stdlib.h>

int parity(int n);

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

		fscanf(ip, "%d", &value);
		printf("%u\n", parity(value));
	}

	fclose(ip);
}

int parity(int n)
{
	int i;
	int value;
	int par = 0;

	value = n & 0x7FFFFFFF;

	for(i=0; i<31; i++)
	{
		par ^= value & 0x01;
		value >>=1;
	}

	if(par) {
		n |= 0x80000000;
	}

	return n;
}