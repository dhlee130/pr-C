#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
	int noca;
	int i, j;
	int a;
	char b;
	unsigned int num, sum, val;
	int ipv[4];
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		sum = 0;
		fscanf(ip, "%d", &a);
		if(a==1)
		{
			for(j=0; j<4; j++)
			{
				fscanf(ip, "%d", &ipv[j]);
				fscanf(ip, "%c", &b);
				sum += ipv[j]*powl(2, 8*(3-j));
			}
			printf("%u\n", sum);
		}
		else
		{
			fscanf(ip, "%d", &num);
			
			val = num & 0xFF000000;
			ipv[0] = (val/0x01000000);
			val = num & 0x00FF0000;
			ipv[1] = (val/0x00010000);
			val = num & 0x0000FF00;
			ipv[2] = (val/0x00000100);
			ipv[3] = num & 0x000000FF; 

			printf("%d.", ipv[0]);
			printf("%d.", ipv[1]);
			printf("%d.", ipv[2]);
			printf("%d\n", ipv[3]);
			
		}
	}


	fclose(ip);
}