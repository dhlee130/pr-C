#include <stdio.h>
#include <stdlib.h>

int med(int a, int b, int c);

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

		printf("%d\n", med(a, b, c));
	}


	fclose(ip);
}

int med(int a, int b, int c)
{
	if(a >= b)
	{
		if(b>=c)
			return b;
		else if(a>=c)
			return c;
		else
			return a;
	}
	if(b >=c)
	{
		if(c>=a)
			return c;
		else if(b>=a)
			return a;
		else
			return b;
	}
	if(c>=a)
	{
		if(a>=b)
			return a;
		else if(c>=b)
			return b;
		else
			return c;
	}

}