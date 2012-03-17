#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
	int Area;
	double Radius,x,y;
	int Year;
	int CaseCount,i;

	scanf("%d",&CaseCount);

	for(i=0;i<CaseCount;i++)
	{
		scanf("%lf %lf",&x,&y);
		Radius = sqrt(x * x + y * y);
		Year = 1;
		Area = 50;

		while(Area < Radius * Radius * PI / 2)
		{
			Area += 50;
			Year++;
		}

		printf("Property %d: This property will begin eroding in year %d.\n",i + 1,Year);
	}

	printf("END OF OUTPUT.\n");

	return 0;
}