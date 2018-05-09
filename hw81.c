#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca, num;
	int i, j, k;
	int fir, sec, sum;
	int arr[11];

	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &num);
		
	
		for(k=0; k<11; k++)
		{
			arr[k] = 0;
		}

		for(j=0;j<num;j++)
		{
			fscanf(ip,"%d %d",&fir, &sec);
			sum = 0;
			sum = fir + sec;
			sum -=2;
			arr[sum] +=1;
			
		}

		for(k=0; k<11; k++)
		{
			printf("%d ", arr[k]);
			if(k==10)
				printf("\n");
		}

	}


	fclose(ip);
}