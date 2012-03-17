#include <stdio.h>

int main()
{
	long CompetitorCount;
	int Round;
	int AddCompetitor;

	while(scanf("%ld",&CompetitorCount) , CompetitorCount != 0)
	{
		Round = 0;
		AddCompetitor = 0;
		
		while(CompetitorCount > 1)
		{
			if(CompetitorCount % 2 == 1)
			{
				CompetitorCount--;
				AddCompetitor = 1;
			}

			CompetitorCount /= 2;
			Round++;

			if(AddCompetitor == 1)
			{
				CompetitorCount++;
				AddCompetitor = 0;
			}
		}

		printf("%d\n",Round);
	}

	return 0; 
}