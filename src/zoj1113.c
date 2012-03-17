#include <stdio.h>

double jiecheng(int);

int main()
{
	int n,i;
	double e;

	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");

	for(n=3;n<=9;n++)
	{
		e=0;
		for(i=0;i<=n;i++)
		{
			e+=jiecheng(i);
		}

		printf("%d %.9lf\n",n,e);
	}

	return 0;
}

double jiecheng(int x)
{
	double re;

	if(x==0)
		re=1.0;
	else
	{
		int i;
		re=1;
		for(i=2;i<=x;i++)
		{
			re*=i;
		}

		re=1/re;
	}

	return re;
}
