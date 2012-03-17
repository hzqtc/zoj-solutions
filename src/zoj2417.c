#include <stdio.h>

int main()
{
	int iMask;
	int iLen;
	int iReturn,iReadin;

	while(scanf("%d",&iReadin),iReadin != 0)
	{
		iMask = 1;
		iLen = 0;

		while((iMask  & iReadin) == 0)
		{
			iMask <<= 1;
			iLen++;
		}

		iReturn &= iMask;
		iReturn |= iMask;

		printf("%d\n",iReturn);
	}

	return 0;
}