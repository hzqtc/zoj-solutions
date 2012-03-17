#include <stdio.h>
#include <math.h>

int main()
{
	double lfTemperature,lfTempPre;
	int iFirst = 1;

	while(scanf("%lf",&lfTemperature) , lfTemperature != 999)
	{
		if(iFirst == 1)
		{
			iFirst = 0;
		}
		else
		{
			printf("%.2lf\n",lfTemperature - lfTempPre);
		}
		lfTempPre = lfTemperature;
	}
	puts("End of Output");

	return 0;
}