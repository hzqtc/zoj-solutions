#include <stdio.h>

struct player
{
	int won;
	int loss;
}anna,betty,cindy,zelda;

int main()
{
	while(scanf("%d %d %d %d %d %d",&betty.won,&betty.loss,&cindy.won,&cindy.loss,&zelda.won,&zelda.loss) , (betty.won | betty.loss | cindy.won | cindy.loss | zelda.won | zelda.loss) != 0)
	{
		anna.loss = betty.won + cindy.won - zelda.loss;
		anna.won = betty.loss + cindy.loss - zelda.won;

		printf("Anna's won-loss record is %d-%d.\n",anna.won,anna.loss);
	}

	return 0;
}
