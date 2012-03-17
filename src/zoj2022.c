#include <stdio.h>

int main()
{
	int numcount,i;
	int num,j;
	int zero;
	int base[] ={5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};

	scanf("%d",&numcount);
	for(i=0;i<numcount;i++)
	{
		scanf("%d",&num);
		zero = 0;
		for(j=0;j<12 && base[j]<=num;j++)
		{
			zero += num / base[j];
		}
		printf("%d\n",zero);
	}

	return 0;
}