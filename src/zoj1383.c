#include <stdio.h>

int main()
{
	long lMask = 1;
	long lTest;
	int iCount,i,j;

	scanf("%d",&iCount);

	for(i=0;i<iCount;i++)
	{
		scanf("%ld",&lTest);

		j = 0;
		while(((lMask << j++) & lTest) == 0)
			;
		printf("%d",j - 1);

		for(;j<32;j++)
		{
			if(((lMask << j) & lTest) != 0) printf(" %d",j);
		}
		putchar('\n');
	}

	return 0;
}