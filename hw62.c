#include <stdio.h>
#include <stdlib.h>

unsigned long byte(unsigned long n, int a, int b, int c, int d);
unsigned long move(unsigned long n, int from, int to);

void main(void)
{
	int noca;
	FILE *ip;

	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	while(noca--)
	{
		unsigned long value;
		int a, b, c, d;

		fscanf(ip, "%lu %d %d %d %d", &value, &a, &b, &c, &d);
		printf("%u\n", byte(value, a, b, c, d));

	}
	fclose(ip);
}

unsigned long byte(unsigned long n, int a, int b, int c, int d)
{
	unsigned long code = 0;

	code |= move(n, a, 4);
	code |= move(n, b, 3);
	code |= move(n, c, 2);
	code |= move(n, d, 1);

	return code;
}

unsigned long move(unsigned long n, int from, int to)
{
	unsigned long mask = 0x00FF;
	unsigned long code = 0;

	switch(from)
	{
	case 1:  break;
	case 2:  mask <<=8; break;
	case 3:  mask <<=16; break;
	case 4:  mask <<=24; break;
	}
	code = n & mask;

	if(to>from)
		code <<= (to-from)*8;
	else if(to<from)
		code >>= (from-to)*8;
	return code;

}
