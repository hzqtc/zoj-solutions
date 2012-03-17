#include <stdio.h>

int main()
{
	int iLineCount,i;
	long lMyLong;
	int iOddNum,iPower;

	scanf("%d",&iLineCount);

	for(i=0;i<iLineCount;i++)
	{
		scanf("%ld",&lMyLong);
		iPower = 0;

		while(lMyLong % 2 == 0)
		{
			iPower++;
			lMyLong /= 2;
		}
		iOddNum = lMyLong;

		printf("%d %d\n",iOddNum,iPower);
	}

	return 0;
}