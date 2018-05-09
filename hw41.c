#include <stdio.h>
#include <stdlib.h>

#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

void main(void)
{
	FILE *ip;
	int x1, y1, x2, y2;
	int a1, b1, a2, b2;
	int noca;
	int i;

	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d %d %d %d", &x1, &y1, &x2, &y2);
		fscanf(ip, "%d %d %d %d", &a1, &b1, &a2, &b2);
		
		if(x1 == x2) // (x.y)수직 (a,b)수평  b1=b2
		{
			if((x1==a1 || x1==a2) && ((b1>=MIN(y1,y2)) && (b1<=MAX(y1,y2)))) {
				printf("2\n");
			}
			else if((b1==y1 || b1==y2) && ((x1>=MIN(a1,a2)) && (x1<=MAX(a1,a2)))) {
				printf("2\n");
			}
			else if(((x1>MIN(a1,a2)) && (x1<MAX(a1,a2))) && ((b1>MIN(y1,y2)) && (b1<MAX(y1,y2)))) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else //(a,b)수직     a1=a2  y1=y2
		{
			if((a1==x1 || a1 ==x2) && ((y1>=MIN(b1,b2)) && (y1<=MAX(b1,b2)))) {
				printf("2\n");
			}
			else if((y1==b1 || y1==b2) && ((a1>=MIN(x1,x2)) && (a1<=MAX(x1,x2)))) {
				printf("2\n");
			}
			else if(((a1>MIN(x1,x2)) && (a1<MAX(x1,x2))) && ((y1>MIN(b1,b2)) && (y1<MAX(b1,b2)))) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
	}
	fclose(ip);
}
