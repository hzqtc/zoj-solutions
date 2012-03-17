#include <stdio.h>
#include <math.h>

#define IPLEN 8

int main()
{
	int Bin2Dec(int *);

	int IPBin[IPLEN],IPDec;
	int TestCount,i,j,k;

	scanf("%d",&TestCount);

	for(i=0;i<TestCount;i++)
	{			
		while(getchar() != '\n')
			;

		for(k=0;k<4;k++)
		{
			for(j = 0;j<IPLEN;j++)
			{
				IPBin[j] = getchar() - '0';
			}
			IPDec = Bin2Dec(IPBin);

			if(k < 3)
				printf("%d.",IPDec);
			else
				printf("%d\n",IPDec);
		}
	}

	return 0;
}

int Bin2Dec(int * IPstr)
{
	int i,IPDec = 0;

	for(i=IPLEN-1;i>=0;i--)
	{
		if(IPstr[i] != 0)
			IPDec += (int)pow(2,IPLEN - i - 1);
	}

	return IPDec;
}