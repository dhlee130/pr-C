#include <stdio.h>
#include <stdlib.h>

void num(int a, int b, int c);

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
		num(a, b, c);
	}


	fclose(ip);
}

void num(int a, int b, int c)
{
	int num1, num2, num3; // Å«¼ø¼­

	if(a >= b)
	{
		if(b>=c)
		{
			num1 = a;
			num2 = b;
			num3 =c;
		}
		else if(a>=c)
		{
			num1 = a;
			num2 = c;
			num3 = b;

		}
		else
		{
			num1 = c;
			num2 = a;
			num3 = b;
		}
	}
	if(b >=c)
	{
		if(c>=a)
		{
			num1 = b;
			num2 = c;
			num3 = a;
		}
		else if(b>=a)
		{
			num1 = b;
			num2 = a;
			num3 = c;
		}
		else
		{
			num1 = a;
			num2 = b;
			num3 = c;
		}
	}
	if(c>=a)
	{
		if(a>=b)
		{
			num1 = c;
			num2 = a;
			num3 = b;
		}
		else if(c>=b)
		{
			num1 = c;
			num2 = b;
			num3 = a;
		}
		else
		{
			num1 = b;
			num2 = c;
			num3 = a;
		}
	}
	printf("%d %d %d\n", num3, num2, num1);
}