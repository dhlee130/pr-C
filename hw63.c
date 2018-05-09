#include <stdio.h>
#include <stdlib.h>

int weight(unsigned int num);
int distance(unsigned int n1, unsigned int n2);
unsigned int xor(unsigned int x, unsigned int y);

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
		unsigned int num1, num2;

		fscanf(ip, "%d %d", &num1, &num2);

		printf("%d %d %d\n", weight(num1), weight(num2), weight(num1^num2));
	}


	fclose(ip);
}

int weight(unsigned int num)
{
	int weight = 0;
	
	while(num)
	{
		if(num & 0x01)
			weight++;
		num>>=1;
	}

	return weight;
}

