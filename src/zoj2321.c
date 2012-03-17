#include <stdio.h>

struct Player
{
	double	Speed;
	int		Weight;
	int		Strength;
};

struct Player WideReceiver = {4.5,150,200},Lineman = {6.0,300,500},Quarterback = {5.0,200,300};

int main()
{
	int SuitPosition(struct Player *,struct Player *);

	int GetPositon;
	struct Player SchoolPlayer;

	while(scanf("%lf %d %d",&SchoolPlayer.Speed,&SchoolPlayer.Weight,&SchoolPlayer.Strength) , SchoolPlayer.Strength != 0)
	{
		GetPositon = 0;

		if(SuitPosition(&WideReceiver,&SchoolPlayer))
		{
			printf("Wide Receiver");
			GetPositon = 1;
		}
		if(SuitPosition(&Lineman,&SchoolPlayer))
		{
			if(GetPositon == 1) putchar(' ');
			printf("Lineman");
			GetPositon = 1;
		}
		if(SuitPosition(&Quarterback,&SchoolPlayer))
		{
			if(GetPositon == 1) putchar(' ');
			printf("Quarterback");
			GetPositon = 1;
		}

		if(GetPositon == 1)
			putchar('\n');
		else
			puts("No positions");
	}
}

int SuitPosition(struct Player * P1,struct Player * P2)
{
	if(P2->Speed <= P1->Speed && P2->Weight >= P1->Weight && P2->Strength >= P1->Strength)
		return 1;
	else
		return 0;
}
