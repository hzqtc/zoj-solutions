#include <stdio.h>

int main()
{
	int n,i;
	int x,y;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		if(x<y)
			printf("NO BRAINS\n");
		else
			printf("MMM BRAINS\n");
	}

	return 0;
}