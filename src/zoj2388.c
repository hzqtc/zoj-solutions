#include <stdio.h>

int main()
{
	int iCount,iSum,iDiffer;
	int iScore1,iScore2;
	int i;

	scanf("%d",&iCount);

	for(i=0;i<iCount;i++)
	{
		scanf("%d%d",&iSum,&iDiffer);

		if(iSum < iDiffer)
			puts("impossible");
		else
		{
			iScore1 = (iSum + iDiffer) / 2;
			iScore2 = (iSum - iDiffer) / 2;

			if(iScore1 + iScore2 == iSum && iScore1 - iScore2 == iDiffer)
			{
				printf("%d %d\n",iScore1,iScore2);
			}
			else
			{
				puts("impossible");
			}
		}
	}

	return 0;
}
