#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i;
	int j, num, val;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &num);
		val = 1;
		for(j=2; j<num; j++)
		{
			if(num%j==0)
			{
				val = 0;
				break;
			}
			
		}
		printf("%d\n", val);
	}


	fclose(ip);
}