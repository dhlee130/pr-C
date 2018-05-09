#include <stdio.h>
#include <stdlib.h>

int length(int n);

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
		int n;

		fscanf(ip, "%d", &n);
		printf("%d\n", length(n));
	}


	fclose(ip);
}

int length(int n)
{
	int len = 1;

	while(n != 1)
	{
		if(n%4==0)
		{
			n = n/4;
			len++;
		}
		else if(n%2==0)
		{
			n = n/2;
			len++;
		}
		else
		{
			n = (n*3)+1;
			len++;
		}
	}

	return len;


}