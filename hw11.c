#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca, noda;
	int i, j;
	int a, b;
	int z, x, c, v, n;

	FILE *ip;
	
	ip = fopen("input.txt", "r");
	if(ip == NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		z=0;
		x=0;
		c=0;
		v=0;
		n=0;
		fscanf(ip, "%d", &noda);
		fscanf(ip, "%d", &a);

		for(j=1; j<noda; j++)
		{
			
			fscanf(ip, "%d", &b);
			if(a>=b){
				z++;
			}
			if(a<=b){
				x++;
			}
			if(a==b){
				c++;
			}
			if(a-b>5 || b-a>5){
				v++;
			}
			if(a%b==0 || b%a==0){
				n++;
			}
			
			a=b;
		}
		printf("%d %d %d %d %d\n", z, x, c, v, n);
	}
	fclose(ip);
}