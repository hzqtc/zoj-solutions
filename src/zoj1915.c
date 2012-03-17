#include <stdio.h>

#define MAX 1000

int main()
{
	int iDataConu,iStudentCount,iAboveCount,iStdScore[MAX];
	int i,j;
	int iSum,iAverage;

	scanf("%d",&iDataConu);

	for(i=0;i<iDataConu;i++)
	{
		scanf("%d",&iStudentCount);

		iSum = 0;
		for(j=0;j<iStudentCount;j++)
		{
			scanf("%d",&iStdScore[j]);
			iSum += iStdScore[j];
		}

		iAverage = iSum / iStudentCount;

		iAboveCount = 0;
		for(j=0;j<iStudentCount;j++)
		{
			if(iStdScore[j] > iAverage) iAboveCount++;
		}

		printf("%.3lf%%\n",(double)iAboveCount / (double)iStudentCount * 100);
	}

	return 0;
}