#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i;
	unsigned int num, sum, check, val, ans;
	
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		sum =0;
		fscanf(ip, "%d", &num);
		
		val = num & 0xFF000000;
		sum += (val/0x01000000);
		val = num & 0x00FF0000;
		sum += (val/0x00010000);
		val = num & 0x0000FF00;
		sum += (val/0x00000100);
		check = num & 0x000000FF;

		while(sum >=256)
		{
			sum -= 256;
		}
		
		ans = 255 - sum;
		
		if(ans == check)
			printf("1\n");
		else
			printf("0\n");
	}


	fclose(ip);
}