#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main(void)
{
	int noca;
	int i, j;
	int num;
	
	char word[101];
	FILE *ip;
	ip = fopen("input.txt", "r");
	if(ip==NULL) exit(1);

	fscanf(ip, "%d", &noca);

	for(i=0; i<noca; i++)
	{
		fscanf(ip, "%d", &num);

		
		fscanf(ip, "%s", &word);

		for(j=0; j<101; j++)
		{
			if(word[j] == '\0')
				break;
			else if(isupper(word[j]))
			{
				word[j] += num;
				if(isupper(word[j])==0)
					word[j] -= 26;
				
				printf("%c", word[j]);
			}
			else if(islower(word[j]))
			{
				if(word[j]+num>127)
					word[j] -= 26;

				word[j] += num;
				if(islower(word[j])==0)
					word[j] -= 26;

				printf("%c", word[j]);
			}
			else
				printf("%c", word[j]);
		}
		printf("\n");
	}


	fclose(ip);
}