#include <stdio.h>

int main()
{
	double money;
	double average=0;
	int i=0;

	for(;i<12;i++)
	{
		scanf("%lf",&money);
		average += money;
	}

	printf("$%.2lf\n",average/=12);

	return 0;
}