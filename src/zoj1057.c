#include <stdio.h>
#include <stdlib.h>

int main()
{
	int round;
	int * p1,* p2;
	int score1,score2;
	int i,count=0;

	while(scanf("%d",&round),round != 0)
	{
		if((p1 = (int *)calloc(round,sizeof(int))) != NULL && (p2 = (int *)calloc(round,sizeof(int))) != NULL)
		{
			if(count != 0) putchar('\n');
			count++;

			score1 = score2 = 0;

			for(i=0;i<round;i++)
				scanf("%d",&p1[i]);
			for(i=0;i<round;i++)
				scanf("%d",&p2[i]);

			for(i=0;i<round;i++)
			{
				if(p1[i] - p2[i] == 1)
				{
					if(p2[i] == 1)
						score2 +=6;
					else
						score2 += p1[i] + p2[i];
				}
				else if(p2[i] - p1[i] == 1)
				{
					if(p1[i] == 1)
						score1 +=6;
					else
						score1 += p1[i] + p2[i];
				}
				else if(p1[i] - p2[i] > 1)
				{
					score1 += p1[i];
				}
				else if(p2[i] - p1[i] > 1)
				{
					score2 += p2[i];
				}
			}

			printf("A has %d points. B has %d points.\n",score1,score2);

			free(p1);
			free(p2);
		}
	}

	return 0;
}