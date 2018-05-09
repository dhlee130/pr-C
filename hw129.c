#include <stdio.h>
#include <stdlib.h>

#define size 8

int queen(int m[][size]);

void main(void)
{
	FILE *file;
	int cases;

	file=fopen("input.txt","r");
	if(file==NULL) exit(1);

	fscanf(file,"%d",&cases);

	while(cases--)
	{
		int i,j,data2,k;
		char data1;
		char x[size+1]="abcdefgh";
		int y[size]={8,7,6,5,4,3,2,1};
		int chess[size][size]={0};

		for(k=0;k<16;k++)
		{
			fscanf(file,"%c%d",&data1,&data2);
			for(i=0;i<size;i++)
			{
				for(j=0;j<size;j++)
				{
					if(x[j]==data1&&y[i]==data2)
					{
						chess[i][j]=1;
					}
					if(x[i]==data1&&y[j]==data2)
					{
						chess[j][i]=1;
					}
				}
			}
		}
		printf("%d \n",queen(chess));
	}
	fclose(file);
}


int queen(int m[][size])
{
	int i,j;
	int count1,count2;
	for(i=0;i<size;i++)
	{
		count1=0;
		count2=0;
		for(j=0;j<size;j++)
		{
			if(m[i][j]==1)
			{
				count1++;
			}
			if(m[j][i]==1)
			{
				count2++;
			}
		}
		if(count1>1||count2>1)
		{
			return 0;
			break;
		}
	}
	for(i=0;i<size;i++)
	{
		count1=0;
		count2=0;
		for(j=0;j<=i;j++)
		{
			if(m[i-j][j]==1)
			{
				count1++;
			}
			if(m[7-i+j][7-j]==1)
			{
				count2++;
			}
		}
		if(count1>1||count2>1)
		{
			return 0;
			break;
		}
		
	}
	for(i=0;i<size;i++)
	{
		count1=0;
		count2=0;
		for(j=0;j<=i;j++)
		{
			if(m[7-i+j][j]==1)
			{
				count1++;
			}
			if(m[i-j][7-j]==1)
			{
				count2++;
			}
		}
		if(count1>1||count2>1)
		{
			return 0;
			break;
		}
	}
	return 1;
}
