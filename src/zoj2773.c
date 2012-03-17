#include <stdio.h>

int main()
{
	int CaseCount,i;
	int n,Sum,t;
	int j;
	
	scanf("%d",&CaseCount);
	
	for(i=0;i<CaseCount;i++)
	{
		scanf("%d",&n);
		
		Sum = 0;
		t = 1;
		
		for(j=1;j<=n;j++)
		{
			t += j + 1;
			Sum += j * t;
		}
		
		printf("%d %d %d\n",i + 1,n,Sum);
	}
	
	return 0;
}