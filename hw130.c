#include <stdio.h>
#include <stdlib.h>

#define SIZE 102

void lifegame(int board[][SIZE], int x, int y, int time);

int life(int sum);

void main(void)
{
	int noca;
	int i, j, k;
	int time, x, y;
	char z[101];
	char a;
	int board[102][102] = {0};
	
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d %d", &y, &x);
		
		fscanf(ip, "%d", &time);

		for(j=1; j<y+1; j++)
		{
			

			for(k=1; k<x+1; k++)
			{
				board[k][j] = 0;
				
			}
		}

		for(j=1; j<y+1; j++)
		{
			fscanf(ip, "%s", &z);

			for(k=1; k<x+1; k++)
			{
				if(z[k-1]=='O')
					board[k][j]++;
				
			}
		}

		
		

		lifegame(board, x, y, time);
	}


	fclose(ip);
}

void lifegame(int board[][SIZE], int x, int y, int time)
{
	int i, j, k;
	int sum;
	int count = 0;

	int board2[102][102] = {0};

	for(i=1; i<y+1; i++)
	{
		for(j=1; j<x+1; j++)
		{
			board2[j][i] = board[j][i];
		}
	}

	
	
	for(k=0; k<time; k++)
	{
		for(j=1; j<y+1; j++)
		{
			for(i=1; i<x+1; i++)
			{
				sum = board[i-1][j-1] + board[i][j-1] + board[i+1][j-1] + board[i-1][j] + board[i+1][j]+ board[i-1][j+1] + board[i][j+1] + board[i+1][j+1];

				board2[i][j] = board[i][j] + life(sum);

				if(board2[i][j] == 2)
					board2[i][j] = 1;
				if(board2[i][j] == (-1))
					board2[i][j] = 0;
			}
		}

		for(i=1; i<y+1; i++)
			{
				for(j=1; j<x+1; j++)
				{
					board[j][i] = board2[j][i];
				}
			}
	}

	

	for(i=1; i<y+1; i++)
	{
		for(j=1; j<x+1; j++)
		{
			if(board[j][i]==1)
				count++;
		}
	}

	printf("%d\n", count);

	for(i=1; i<y+1; i++)
	{
		for(j=1; j<x+1; j++)
		{
			if(board[j][i] == 1)
				printf("O");
			else
				printf("X");
		}
		printf("\n");
	}
}

int life(int sum)
{
	int a;

	if(sum<2 || sum>3)
		a = (-1);
	else if(sum == 3)
		a = 1;
	else
		a = 0;

	return a;
}