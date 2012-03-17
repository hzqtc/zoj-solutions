#include <stdio.h>

#define MAX	100000

int main()
{
	void init(int * num);
	
	int number[MAX];/*用于标记数字是否已经产生的数组，1表示已经产生，0表示没有产生*/
	long step,mod,seed,i;
	
	while(scanf("%d %d",&step,&mod) != EOF)
	{
		init(number);
		seed = 0;
		printf("%10d%10d",step,mod);
		
		while(1)
		{
			if(number[seed] == 0)/*未产生的数字标记为已产生*/
				number[seed] = 1;
			else if(number[seed] == 1)/*循环了一个周期*/
			{
				for(i=0;i<mod-1;i++)
				{
					if(number[i] == 0)
						break;
				}
				if(i >= mod - 1)
					printf("    Good Choice\n\n");
				else
					printf("    Bad Choice\n\n");
					
				break;
			}
			seed = (seed + step) % mod;	
		}
	}
}

void init(int * num)
{
	long i = 0;
	
	for(;i<MAX;i++)
	{
		num[i] = 0;
	}
}