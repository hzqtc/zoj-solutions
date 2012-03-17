#include <stdio.h>

#define PI 3.1415927

int main()
{
	double lfDiameter,lfTime;/*直径（英寸）、时间（秒）*/
	int iRevolutions;/*转数（次）*/
	double lfDistance,lfMPH;/*行程（英里）、平均速度（英里每小时）*/
	int iCount = 0;

	while(scanf("%lf%d%lf",&lfDiameter,&iRevolutions,&lfTime) , iRevolutions != 0)
	{
		iCount++;

		lfDistance = (double)iRevolutions * lfDiameter * PI / 12.0 / 5280.0;
		lfMPH = lfDistance / lfTime * 3600.0;

		printf("Trip #%d: %.2lf %.2lf\n",iCount,lfDistance,lfMPH);
	}

	return 0;
}
