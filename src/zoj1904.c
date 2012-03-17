#include <stdio.h>
#include <math.h>

#define PI 3.141592653590

int main()
{
	double xd,dd;
	double v;
	
	while(scanf("%lf%lf",&dd,&v) , dd && v)
	{
		xd = pow(dd * dd * dd - 6 * v / PI,0.333333333);
		printf("%.3lf\n",xd);
	}

	return 0;
}
