#include <stdio.h>

#define MAXCOUNT 100

int main()
{
	int iDevice,iOperationCount,iFuseCapcity,iMaxPower,iCurrentPower;
	int iDevPower[MAXCOUNT],iSate[MAXCOUNT];
	int iOpeIndex,i,iIndex = 1;

	while(scanf("%d%d%d",&iDevice,&iOperationCount,&iFuseCapcity) , iDevice != 0 && iOperationCount != 0 && iFuseCapcity != 0)
	{
		iMaxPower = 0;
		iCurrentPower = 0;

		for(i=0;i<iDevice;i++)
		{
			scanf("%d",iDevPower + i);
			iSate[i] = 0;/*¹Ø±ÕÈ«²¿*/
		}

		for(i=0;i<iOperationCount;i++)
		{
			scanf("%d",&iOpeIndex);

			iOpeIndex--;
			
			if(iSate[iOpeIndex] == 0)
			{
				iSate[iOpeIndex] = 1;
				iCurrentPower += iDevPower[iOpeIndex];
			}
			else
			{
				iSate[iOpeIndex] = 0;
				iCurrentPower -= iDevPower[iOpeIndex];
			}

			if(iCurrentPower > iMaxPower) iMaxPower = iCurrentPower;
		}

		if(iMaxPower > iFuseCapcity)
		{
			printf("Sequence %d\nFuse was blown.\n\n",iIndex);
		}
		else
		{
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",iIndex,iMaxPower);
		}

		iIndex++;
	}

	return 0;
}