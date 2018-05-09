#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k, n;
	int num;
	int arr[100];

	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &n);

		for(j=0; j<n; j++)
		{
			fscanf(ip, "%d", &arr[j]);
		}

		for(k=n; k>=2; k--)
		{
			for(j=0; j<k-1; j++)
			{
				if(arr[j]>arr[j+1])
				{
					num = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = num;
				}
			}
		}

		for(j=0; j<n; j++)
			printf("%d ", arr[j]);

		printf("\n");

	}


	fclose(ip);
}