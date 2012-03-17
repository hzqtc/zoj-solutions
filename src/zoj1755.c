#include <stdio.h>

struct std
{
	char szName[9];
	int iCube;
}Student[9];

int main()
{
	int iStdCount,i;
	int a,b,c;
	struct std * stdpBully,* stdpVictim;

	while(scanf("%d",&iStdCount) , iStdCount != -1)
	{
		for(i=0;i<iStdCount;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			Student[i].iCube = a * b * c;
			scanf("%s",Student[i].szName);
			if(i == 0)
			{
				stdpVictim = stdpBully = &Student[i];
			}
			else
			{
				if(Student[i].iCube > stdpBully->iCube)
				{
					stdpBully = &Student[i];
				}

				if(Student[i].iCube < stdpVictim->iCube)
				{
					stdpVictim = &Student[i];
				}
			}
		}
		printf("%s took clay from %s.\n",stdpBully->szName,stdpVictim->szName);
	}

	return 0;
}