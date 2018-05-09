#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i;
	int a, b, c;
	int num;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &a);
		fscanf(ip, "%d", &b);
		fscanf(ip, "%d", &c);

		if(a<=b)
		{
			num = b;
			if(b<=c)
			{
				num =c;
			}
		}
		else if(b<=a)
		{
			num = a;
			if(a<=c)
			{
				num = c;
			}
		}
		else if(b<=c)
		{
			num = c;
			if(c<=a)
			{
				num = a;
			}
		}
		else if(c<=b)
		{
			num = b;
			if(b<=a)
			{
				num = a;
			}
		}
		else if(c<=a)
		{
			num = a;
			if(a<=b)
			{
				num = b;
			}
		}
		else if(a<=c)
		{
			num = c;
			if(c<=b)
			{
				num = b;
			}
		}
		printf("%d\n", num);
	}


	fclose(ip);
}