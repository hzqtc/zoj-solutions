#include <stdio.h>
#include <math.h>

#define MAX 64

int main()
{
	int commonfactor(int a,int b);

	int numcount,i,j;
	int num[MAX];
	int nocommon;

	while(scanf("%d",&numcount) != EOF && numcount != 0)
	{
		for(i=0;i<numcount;i++)
		{
			scanf("%d",&num[i]);
		}
	
		nocommon = 0;
		for(i=0;i<numcount-1;i++)
		{
			for(j=i+1;j<numcount;j++)
			{
				if(commonfactor(num[i],num[j]) == 1)
					nocommon++;
			}
		}

		if(nocommon == 0)
			printf("No estimate for this data set.\n");
		else
			printf("%.6lf\n",(double)sqrt(3.0 * numcount * (numcount - 1) / nocommon));
	}

	return 0;
}

int commonfactor(int a,int b)
{
	int r = 0;

	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}
