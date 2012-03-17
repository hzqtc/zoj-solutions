#include <stdio.h>

int main()
{
	int Crashed = 0;
	int i;
	int UnderpassHeight;

	for(i=0;i<3;i++)
	{
		scanf("%d",&UnderpassHeight);

		if(Crashed == 0)
		{
			if(UnderpassHeight <= 168)
				Crashed = UnderpassHeight;
		}
	}

	if(Crashed > 0)
		printf("CRASH %d\n",Crashed);
	else
		puts("NO CRASH\n");

	return 0;
}