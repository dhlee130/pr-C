#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEAM 100

typedef struct {
	int win, draw, loss;
	int point;
	char name[1];
} SOCCERTEAM;

SOCCERTEAM *europeanLeague[MAX_TEAM];
int numTeams;

void inputTeams(FILE *inFile);
int compareTeam(const void *a, const void *b);
void printTeams();

void main()
{
	FILE *inFile;
	int numtestcases;

	inFile = fopen("input.txt", "r");
	if(inFile == NULL) exit(1);

	fscanf(inFile, "%d", &numtestcases);

	while(numtestcases--)
	{
		int i;

		inputTeams(inFile);
		qsort(europeanLeague, numTeams, sizeof(SOCCERTEAM *), compareTeam);
		printTeams();

		for(i=0; i<numTeams; i++)
			free(europeanLeague[i]);
	}

	fclose(inFile);
}

/*�� ���� ��� �����͸� �Է��ϴ� �Լ�*/
#define MAX_LENGTH (30+1)

void inputTeams(FILE *inFile)
{
	int i;
	int w, d, l;
	char name[MAX_LENGTH];

	fscanf(inFile, "%d", &numTeams);
	for(i=0; i<numTeams; i++)
	{
		SOCCERTEAM *team;

		fscanf(inFile, "%s %d %d %d", name, &w, &d, &l);
		team = (SOCCERTEAM *) malloc(sizeof(SOCCERTEAM) + strlen(name));
		if(team != NULL)
		{
			team->win = w;
			team->draw = d;
			team->loss = l;
			team->point = w*2 + d;
			strcpy(team->name, name);

			europeanLeague[i] = team;
		}
		else
			exit(1);
	}
}

/*�� ���� �켱 ������ ����ϴ� �Լ�*/
int compareTeam(const void *a, const void *b)
{
	SOCCERTEAM *team1 = *(SOCCERTEAM **)a;
	SOCCERTEAM *team2 = *(SOCCERTEAM **)b;

	if((team1->point) > (team2->point))  //����Ʈ�� ��
		return -1;
	else if((team1->point) < (team2->point))
		return 1;
	else    //�¸����� ��
	{
		if((team1->win) > (team2->win))
			return -1;
		else if((team1->win) < (team2->win))
			return 1;
		else  //������ ��
		{
			if((team1->draw) > (team2->draw))
				return -1;
			else if((team1->draw) < (team2->draw))
				return 1;
			else// ������ ��
			{
				if((team1->loss) > (team2->loss))
					return 1;
				else if((team1->loss) < (team2->loss))
					return -1;
				else//������ ��
					strcmp(team1->name, team2->name);

			}
		}
	}
}

/* �� ������ ���� ���� ����ϴ� �Լ�*/
void printTeams()
{
	int i;

	for(i=0; i<numTeams; i++)
	{
		printf("%s %d\n", europeanLeague[i]->name, europeanLeague[i]->point);
	}
}