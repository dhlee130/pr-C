#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca, noda;
	int i, j;
	int a, total;
	int x, y, ans;
	FILE *ip;

	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		total = 1;
		ans = 0;
		fscanf(ip, "%d", &noda);
		x=0;
		y=0;
		for(j=0; j<noda; j++)
		{
			fscanf(ip, "%d", &a);
			while((a%2)==0)
			{
				x++;
				a = a/2;
			}
			while((a%5)==0)
			{
				y++;
				a = a/5;
			}
			
			total *= a;
			
			
		
			while((total%2)==0)
			{
				x++;
				total = total/2;
			}
			while((total%5)==0)
			{
				y++;
				total = total/5;
			}
			if(x<=y)
			{
				ans = x;
			}
			if(x>y)
			{
				ans = y;
			}
		}
		printf("%d\n", ans);
	}


	fclose(ip);


}