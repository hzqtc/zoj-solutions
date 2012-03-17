#include <stdio.h>

int main()
{
	int iCount,i;
	int iTotalTime,iCurrentFloor,iDesFloor;

	while(scanf("%d",&iCount) , iCount > 0)
	{
		iTotalTime = 0;
		iCurrentFloor = 0;

		for(i=0;i<iCount;i++)
		{
			scanf("%d",&iDesFloor);

			if(iDesFloor > iCurrentFloor)
			{
				iTotalTime += 6 * (iDesFloor - iCurrentFloor);
			}
			else if(iDesFloor < iCurrentFloor)
			{
				iTotalTime += 4 * (iCurrentFloor - iDesFloor);
			}
			iTotalTime += 5;
			iCurrentFloor = iDesFloor;
		}

		printf("%d\n",iTotalTime);
	}

	return 0;
}