#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca;
	int i, j, k, l;
	int arr[9][9] = {0};
	int s, t;
	int n;
	int num1, num2;
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &n);

		for(j=1; j<9; j++)
			{
				for(k=1; k<9; k++)
				{
					arr[j][k] = 0;
				}
		}

		num1 = 0;
		num2 = 0;

		arr[4][4] = 2;      //1 흑  2  백   0  빈칸
		arr[4][5] = 1;
		arr[5][4] = 1;
		arr[5][5] = 2;

		for(j=0; j<n; j++)
		{
			if(j%2==0)
			{
				fscanf(ip, "%d %d", &s, &t);

				arr[s][t] = 1;

				for(k=1; s+k<9; k++) //아래
				{
					if(arr[s+k][t]==0)
						break;

					else if(arr[s+k][t] == 1)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s+l][t] == 2)
								arr[s+l][t] = 1;
						}
						break;
					}
				}

				for(k=1; s-k>0; k++)  //위
				{
					if(arr[s-k][t] == 0)
						break;

					else if(arr[s-k][t] == 1)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s-l][t] == 2)
								arr[s-l][t] = 1;
						}
						break;
					}
				}

				for(k=1; t+k<9; k++) //오른쪽
				{
					if(arr[s][t+k] == 0)
						break;

					else if(arr[s][t+k] == 1)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s][t+l] == 2)
								arr[s][t+l] = 1;
						}
						break;
					}
				}

				for(k=1; t-k>0; k++)  //왼쪽
				{
					if(arr[s][t-k] == 0)
						break;

					else if(arr[s][t-k] == 1)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s][t-l] == 2)
								arr[s][t-l] = 1;
						}
						break;
					}
				}

				for(k=1; s+k<9 || t+k<9; k++) // 아래 오른쪽
				{
					if(arr[s+k][t+k] == 0)
						break;
					else if(arr[s+k][t+k] == 1)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s+l][t+l] == 2)
								arr[s+l][t+l] = 1;
						}
						break;
					}
				}

				for(k=1; s-k>0 || t+k<9; k++) // 위 오른쪽
				{
					if(arr[s-k][t+k] == 0)
						break;

					else if(arr[s-k][t+k] == 1)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s-l][t+l] == 2)
								arr[s-l][t+l] = 1;
						}
						break;
					}
				}

				for(k=1; s+k<9 || t-k>0; k++) // 아래 왼쪽
				{
					if(arr[s+k][t-k] == 0)
						break;

					else if(arr[s+k][t-k] == 1)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s+l][t-l] == 2)
								arr[s+l][t-l] = 1;
						}
						break;
					}
				}

				for(k=1; s-k>0 || t-k>0; k++) // 위 왼쪽
				{
					if(arr[s-k][t-k] == 0)
						break;

					else if(arr[s-k][t-k] == 1)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s-l][t-l] == 2)
								arr[s-l][t-l] = 1;
						}
						break;
					}
				}

			}

			else
			{
				fscanf(ip, "%d %d", &s, &t);

				arr[s][t] = 2;

				for(k=1; s+k<9; k++) //아래
				{
					if(arr[s+k][t] == 0)
						break;

					else if(arr[s+k][t] == 2)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s+l][t] == 1)
								arr[s+l][t] = 2;
						}
						break;
					}
				}

				for(k=1; s-k>0; k++)  //위
				{
					if(arr[s-k][t] == 0)
						break;

					else if(arr[s-k][t] == 2)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s-l][t] == 1)
								arr[s-l][t] = 2;
						}
						break;
					}
				}

				for(k=1; t+k<9; k++) //오른쪽
				{
					if(arr[s][t+k] == 0)
						break;

					else if(arr[s][t+k] == 2)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s][t+l] == 1)
								arr[s][t+l] = 2;
						}
						break;
					}
				}

				for(k=1; t-k>0; k++)  //왼쪽
				{
					if(arr[s][t-k] == 0)
						break;

					else if(arr[s][t-k] == 2)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s][t-l] == 1)
								arr[s][t-l] = 2;
						}
						break;
					}
				}

				for(k=1; s+k<9 || t+k<9; k++) // 아래 오른쪽
				{
					if(arr[s+k][t+k] == 0)
						break;

					else if(arr[s+k][t+k] == 2)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s+l][t+l] == 1)
								arr[s+l][t+l] = 2;
						}
						break;
					}
				}

				for(k=1; s-k>0 || t+k<9; k++) // 위 오른쪽
				{
					if(arr[s-k][t+k] == 0)
						break;

					else if(arr[s-k][t+k] == 2)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s-l][t+l] == 1)
								arr[s-l][t+l] = 2;
						}
						break;
					}
				}

				for(k=1; s+k<9 || t-k>0; k++) // 아래 왼쪽
				{
					if(arr[s+k][t-k] == 0)
						break;

					else if(arr[s+k][t-k] == 2)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s+l][t-l] == 1)
								arr[s+l][t-l] = 2;
						}
						break;
					}
				}

				for(k=1; s-k>0 || t-k>0; k++) // 위 왼쪽
				{
					if(arr[s-k][t-k] == 0)
						break;

					else if(arr[s-k][t-k] == 2)
					{
						for(l=1; l<k; l++)
						{
							if(arr[s-l][t-l] == 1)
								arr[s-l][t-l] = 2;
						}
						break;
					}
				}
			}

			
			

		}

		for(j=1; j<9; j++)
			{
				for(k=1; k<9; k++)
				{
					if(arr[j][k] == 1)
						num1++;
					else if(arr[j][k] == 2)
						num2++;
				}
		}

		printf("%d %d\n", num1, num2);

		for(j=1; j<9; j++)
			{
				for(k=1; k<9; k++)
				{
					if(arr[j][k] == 0)
						printf("+");
					else if(arr[j][k] == 1)
						printf("X");
					else 
						printf("O");
				}
				printf("\n");
				}
		

}
	fclose(ip);
}