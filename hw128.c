#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k;
	int n, num, num2;
	int c;
	int matrix[100][100] = {0};
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &n);
		c=1;
		
		num = 0;
		num2 = 0;

		for(j=0; j<n; j++)
		{
			for(k=0; k<n; k++)
			{
				fscanf(ip, "%d", &matrix[j][k]);
			}
		}
		
		for(j=0; j<n; j++)
		{
			num += matrix[0][j];
		}

		for(j=0; j<n; j++)
		{
			for(k=0; k<n; k++)
			{
				num2 += matrix[j][k];
			}
			
			if(num!=num2)
				c=0;
			num2 = 0;
		}

		

		for(j=0; j<n; j++)
		{
			for(k=0; k<n; k++)
			{
				num2 += matrix[k][j];
			}
			
			if(num!=num2)
				c=0;
			num2 = 0;
		}

		

		for(j=0; j<n; j++)
		{
			num2 += matrix[j][j];
		}
		if(num!=num2)
			c=0;

		num2=0;

		for(j=0; j<n; j++)
		{
			num2 += matrix[n-1-j][j];
		}
		if(num!=num2)
			c=0;

		if(c)
			printf("%d\n", num);
		else
			printf("-1\n");
	}


	fclose(ip);
}