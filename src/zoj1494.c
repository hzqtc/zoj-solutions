#include <stdio.h>

int main()
{
	int height,climb,slip,cliheight;
	int mincount;

	while(scanf("%d %d %d",&height,&climb,&slip),height!=0)
	{
		cliheight=0;
		mincount=0;
		while(1)
		{
			cliheight+=climb;
			mincount++;
			if(cliheight>=height) 
				break;
			else
			{
				cliheight-=slip;
				mincount++;
			}
		}

		printf("%d\n",mincount);
	}

	return 0;
}