#include <stdio.h>
#include <stdlib.h>




void main(void)
{
	FILE *ip;
	int i;
	int no;
	int year;
	int c, n, t, i, j, k, l, p, q;
	int month, day;

	ip = fopen("input.txt", "r");
	if(ip == NULL) exit(1);

	fscanf(ip, "%d", &no);

		for(i=0; i<no; i++);
		{
			fscanf(ip, "%d", &year);
			c = year / 100;
	n = year-(year/19*19);
	t = (c-17)/25;
	i = (c-(c/4)-(c-t)/3)+n*19+15;
	j = i-(i/30*30);
	k = (j/28)+(1-j/28)+(29/(j+1))+(21-n)/11;
	l = (year+year/4)+j+2-c+c/4;
	p = (l/7*7)-l;
	q = k-p;
	month = ((q+40)/44)+3;
	day = (q+28)-(month/4*31);

	printf("%d %d\n", month, day);
		}
		fclose(ip);
}

