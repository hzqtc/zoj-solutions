#include <stdio.h>
#include <math.h>

#define PI	3.141592653589793

int main()
{
	double x1,y1,x2,y2,x3,y3;
	double cx1,cy1,cx2,cy2;
	double k1,k2;
	double ox,oy;
	double circumference,temp;
	
	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3) != EOF)
	{
		cx1 = (x1 + x2) / 2;
		cy1 = (y1 + y2) / 2;
		cx2 = (x2 + x3) / 2;
		cy2 = (y2 + y3) / 2;

		if(y2 == y1)		/*"y1 == y2 == y3" is impossible*/
		{
			k2 = -((x3 - x2) / (y3 - y2));
			ox = cx1;
			oy = k2 * (ox - cx2) + cy2;
		}
		else if(y3 == y2)
		{
			k1 = -((x2 - x1) / (y2 - y1));
			ox = cx2;
			oy = k1 * (ox - cx1) + cy1;
		}
		else
		{
			k1  = -((x2 - x1) / (y2 - y1));
			k2  = -((x3 - x2) / (y3 - y2));
			ox  = (cy2 - cy1 + k1 * cx1 - k2 * cx2) / (k1 - k2);
			oy  = (ox - cx1) * k1 + cy1; 
		}

		temp = (ox - x1) * (ox - x1) + (oy - y1) * (oy - y1);
		circumference = 2 * PI * sqrt(temp);
		printf("%.2lf\n",circumference);
	}
	
	return 0;
}
