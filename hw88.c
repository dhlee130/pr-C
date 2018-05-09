#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k;
	int x[6] = {0};
	int y[6] = {0};
	int bonus;
	int score, num;
	int rank;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		score = 0;
		num = 0;
		for(j=0; j<6; j++)
		{
			fscanf(ip, "%d", &x[j]);
		}

		fscanf(ip, "%d", &bonus);

		for(j=0; j<6; j++)
		{
			fscanf(ip, "%d", &y[j]);
		}

		for(j=0; j<6; j++)
		{
			for(k=0; k<6; k++)
			{
				if(y[j]==x[k])
					score++;
			}
			if(y[j] == bonus)
			{
				num = 1;
			}
		}

		if(score==6)
			rank = 1;
		else if(score==5)
		{
			if(num)
				rank = 2;
			else 
				rank = 3;
		}
		else if(score==4)
			rank = 4;
		else if(score==3)
			rank = 5;
		else
			rank = 0;

		printf("%d\n", rank);

	}


	fclose(ip);
}