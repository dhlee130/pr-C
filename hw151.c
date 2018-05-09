#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 101			/* 입력 스트링의 최대길이 +1*/

int isMultipleOf2(char *longint, int length);
int isMultiple0f3(char *longint, int length);
int isMultiple0f4(char *longint, int length);
int isMultiple0f5(char *longint, int length);
int isMultiple0f6(char *longint, int length);
int isMultiple0f7(char *longint, int length);
int isMultiple0f8(char *longint, int length);
int isMultiple0f9(char *longint, int length);
int isMultiple0f10(char *longint, int length);
int isMultiple0f11(char *longint, int length);

typedef int (*pt2FunctionIsMultipleOfK)(char *, int);
pt2FunctionIsMultipleOfK isMultiple0fK[12] = { NULL, NULL,
	isMultipleOf2, isMultiple0f3, isMultiple0f4, isMultiple0f5, isMultiple0f6,
	isMultiple0f7, isMultiple0f8, isMultiple0f9, isMultiple0f10, isMultiple0f11};

void main()
{
	FILE *inFile;
	int i,k;
	int numCases;

	inFile=fopen("input.txt","r");
	if(inFile == NULL) exit(1);

	fscanf(inFile, "%d", &numCases);

	for(i=0; i<numCases; i++)
	{
		char longInteger[MAX_LENGTH];
		int length;

		fscanf(inFile, "%s", longInteger);
		length = strlen(longInteger);

		for(k=2; k<12; k++)
			printf("%d ", isMultiple0fK[k](longInteger,length));

		printf("\n");
	}
	fclose(inFile);
}

/*주어진 수가 k (2<=k<=11)의 배수인지를 검사하는 함수*/
int isMultipleOf2(char *longint, int length)
{
	int lastDigit;

	lastDigit= longint[length-1] - '0';
	if(lastDigit%2==0)
		return 1;
	else
		return 0;
}

int isMultiple0f3(char *longint, int length)
{
	int sum = 0, i;

	for(i=0; i<length; i++)
	{
		sum += (longint[i] -'0');
	}

	if(sum%3==0)
		return 1;
	else 
		return 0;
}

int isMultiple0f4(char *longint, int length)
{
	int num = 0;

	num += longint[length-1] + longint[length-2]*10;

	if(num%4==0)
		return 1;
	else 
		return 0;
}

int isMultiple0f5(char *longint, int length)
{
	int last;

	last = longint[length-1] - '0';

	if(last == 0 || last == 5)
		return 1;
	else 
		return 0;
}

int isMultiple0f6(char *longint, int length)
{
	int lastDigit;
	int sum = 0, i;

	lastDigit= longint[length-1] - '0';
	

	for(i=0; i<length; i++)
	{
		sum += (longint[i] -'0');
	}

	if(lastDigit%2==0 && sum%3==0)
		return 1;
	else
		return 0;
}

int isMultiple0f7(char *longint, int length)
{
	int sum=0;
	int num1=0,num2=0,i=0;
	
	if(length==1)
	{
		if((longint[0]-'0' == 7))
			return 1;
		else
			return 0;
	}

	for(;;)
	{
		if(sum==0)
		{
			sum=(longint[i]-'0')*3 + (longint[i+1] -'0'); 
			i++;
		}
		if(sum>=10)
		{
			num1=sum/10;
			num2=sum%10;
			sum=num1*3+num2;
		}
		if(sum<10)
		{
			i++;
			if(i==length)
			{
				break;
			}
			sum=sum*3+longint[i]-'0';
		}
	}

	

	if(sum==7)
		return 1;
	else
		return 0;

	
}



int isMultiple0f8(char *longint, int length)
{
	int num = 0;

	num += longint[length-1] + longint[length-2]*10 + longint[length-3]*100;

	if(num%8==0)
		return 1;
	else
		return 0;
}

int isMultiple0f9(char *longint, int length)
{
	int sum = 0, i;

	for(i=0; i<length; i++)
	{
		sum += (longint[i] -'0');
	}

	if(sum%9==0)
		return 1;
	else
		return 0;
}

int isMultiple0f10(char *longint, int length)
{
	int last;

	last = longint[length-1] - '0';

	if(last == 0)
		return 1;
	else 
		return 0;
}
int isMultiple0f11(char *longint, int length)
{
	int i, j;
	int sum1 =0, sum2 = 0, num;

	for(i=0; i<length; i+=2)
	{
		sum1 += (longint[i] -'0');
	}

	for(j=1; j<length; j+=2)
	{
		sum2 += (longint[j] -'0');
	}

	if(sum1>=sum2)
		num = sum1 - sum2;
	else
		num = sum2 - sum1;

	if(num%11==0)
		return 1;
	else
		return 0;
}