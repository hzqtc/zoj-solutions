#include <stdio.h>

#define MAX	50
#define ABS(x)	((x) > 0 ? (x) : -(x))

int main()
{
	int brickcount,brick[MAX];
	int sum,average,move;
	int i,setcount = 0;
	
	while(scanf("%d",&brickcount) , brickcount != 0)
	{
		setcount++;
		sum = 0;
		for(i=0;i<brickcount;i++)
		{
			scanf("%d",brick + i);
			sum += brick[i];
		}
		average = sum / brickcount;
		move = 0;
		for(i=0;i<brickcount;i++)
		{
			move += ABS(brick[i] - average);
		}
		move /= 2;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",setcount,move);
	}
	
	return 0;
}
