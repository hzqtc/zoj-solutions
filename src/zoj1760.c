#include <stdio.h>

int main()
{
	int iaRandnum[14],iNumCount,iDblCount;
	int i,j;
	
	while(scanf("%d",&iaRandnum[0]),iaRandnum[0] != -1)
	{
		iNumCount = 1;
		iDblCount = 0;

		while(scanf("%d",&iaRandnum[iNumCount]),iaRandnum[iNumCount] != 0)
		{
			iNumCount++;
		}

		for(i=0;i<iNumCount;i++)
		{
			if(iaRandnum[i] % 2 == 0)
			{
				for(j=0;j<iNumCount;j++)
				{
					if(iaRandnum[i] == iaRandnum[j] * 2)
						iDblCount++;
				}
			}
		}

		printf("%d\n",iDblCount);
	}

	return 0;
}