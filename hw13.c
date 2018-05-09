#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca, noda, num;
	int i, j;
	int a, b;

	FILE *ip;

	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		a=0;
		b=0;
		fscanf(ip, "%d", &noda);

		for(j=0; j<noda; j++)
		{
			fscanf(ip, "%d", &num);
			if(num%2==0)
			{
				b++;
			}
			else
			{
				a++;
			}
		}
		printf("%d %d\n", a, b);
	}
	fclose(ip);

}