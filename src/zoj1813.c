#include <stdio.h>

#define PI 3.1415927

int main()
{
	double lfDiameter,lfTime;/*ֱ����Ӣ�磩��ʱ�䣨�룩*/
	int iRevolutions;/*ת�����Σ�*/
	double lfDistance,lfMPH;/*�г̣�Ӣ���ƽ���ٶȣ�Ӣ��ÿСʱ��*/
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
