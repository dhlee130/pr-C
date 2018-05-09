#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int noca, noda;
	int i, j;
	int a, b, c;
	int q, w, e, r, t;

	FILE *ip;
	
	ip = fopen("input.txt", "r");
	if(ip == NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		q=0;
		w=0;
		e=0;
		r=0;
		t=0;
		fscanf(ip, "%d", &noda);
		fscanf(ip, "%d", &a);
		fscanf(ip, "%d", &b);

		for(j=2; j<noda; j++)
		{
			fscanf(ip, "%d", &c);
			if(a<=b && b<=c)
			{
				q++;
			}
			if(a>=b && b>=c)
			{
				w++;
			}
			if(a==b && b==c)
			{
				e++;
			}
			if((a!=b && b==c) || (a==b && b!=c))
			{
				r++;
			}
			if(a!=b && b!=c)
			{
				t++;
			}
			a=b;
			b=c;
		}
		printf("%d %d %d %d %d\n", q, w, e, r, t);
	}
	fclose(ip);
}