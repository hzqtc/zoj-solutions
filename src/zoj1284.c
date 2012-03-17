#include <stdio.h>

int main()
{
	long num,divisorsum;
	long getdsum(long num);
	
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d",&num) , num != 0)
	{
		if(num != 1)
		{
			divisorsum = getdsum(num);
			printf("%5d  ",num);
			if(divisorsum == num)
				printf("PERFECT\n");
			else if(divisorsum < num)
				printf("DEFICIENT\n");
			else
				printf("ABUNDANT\n");
		}
		else
			printf("%5d  DEFICIENT\n",num);
	}
	printf("END OF OUTPUT\n");
	
	return 0;
}

long getdsum(long num)
{
	long i,max = num,sum = 1;
	
	for(i=2;i<max;i++)
	{
		if(num % i == 0)
		{
			sum += i;
			max = num / i;
			if(max != i)
				sum += max;
		}
	}
	
	return sum;
}
