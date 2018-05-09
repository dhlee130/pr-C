#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k, l;
	int n, a, b;
	int sum;
	int arr[101][101] = {0};
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &n);

		for(j=0; j<n; j++)
		{
			for(k=0; k<n; k++)
			{
				fscanf(ip, "%d", &arr[k][j]);
			}
		}

		fscanf(ip, "%d", &a);
		fscanf(ip, "%d", &b);

		sum = 0;

		if(a>0)
		{
			for(l=a; l<b; l++)
			{
				for(j=0, k=0; j+l<n; j++, k++)
				{
					sum += arr[j+l][k];
				}
			}
		}

		else if(b<0)
		{
			for(l=-b; l<-a; l++)
			{
				for(j=0, k=0; k+l<n; j++, k++)
				{
					sum += arr[j][k+l];
				}
			}
		}


		for(j=0; j<n; j++)
		{
			sum += arr[j][j];

		}

		for(l=1; l<=b; l++)
		{
			for(j=0, k=0; j+l<n; j++, k++)
			{
				sum += arr[j+l][k];
			}
		}

		for(l=1; l<=-1*a; l++)
		{
			for(j=0, k=0; k+l<n; j++, k++)
			{
				sum += arr[j][k+l];
			}
		}

		printf("%d\n", sum);
	}


	fclose(ip);
}