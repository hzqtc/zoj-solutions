#include <stdio.h>

int main()
{
	int gcd(int a,int b);

	int lcm,num;
	int casecount,i;
	int numcount,j;

	scanf("%d",&casecount);
	for(i=0;i<casecount;i++)
	{
		scanf("%d",&numcount);
		lcm = 1;
		for(j=0;j<numcount;j++)
		{
			scanf("%d",&num);
			lcm *= (num / gcd(lcm,num));
		}
		printf("%d\n",lcm);
	}

	return 0;
}

int gcd(int a,int b)
{
	int temp;

	while(a)
	{
		temp = a;
		a = b % a;
		b = temp;
	}

	return b;
}