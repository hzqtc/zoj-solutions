#include <stdio.h>

int main()
{
	int lfOnes;
	int iNum,iOneCount;

	while(scanf("%d",&iNum) != EOF)
	{
		iOneCount = 1;
		lfOnes = 1 % iNum;

		while(lfOnes)
		{
			lfOnes = (lfOnes * 10 + 1) % iNum;
			iOneCount++;
		}
		printf("%d\n",iOneCount);
	}

	return 0;
}
