#include <cstdio>
#include <cmath>

#define square(x) ((x) * (x))

using namespace std;

int main()
{
	double _x1,_x2,_x3,_y1,_y2,_y3,_z1,_z2,_z3;
	double a,b,c;
	double s;
	double sina,cosa;
	double radius_cir,radius_in;

	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&_x1,&_y1,&_z1,&_x2,&_y2,&_z2,&_x3,&_y3,&_z3) != EOF)
	{
		a = sqrt(square(_x1 - _x2) + square(_y1 - _y2) + square(_z1 - _z2));
		b = sqrt(square(_x2 - _x3) + square(_y2 - _y3) + square(_z2 - _z3));
		c = sqrt(square(_x3 - _x1) + square(_y3 - _y1) + square(_z3 - _z1));
		s = (a + b + c) / 2;
		radius_in = 4 * s * (s - a) * (s - b) * (s - c) / square(a + b + c);

		cosa = (b * b + c * c - a * a) / (2 * b * c);
		sina = sqrt(1 - cosa * cosa);
		radius_cir = a / (2 * sina);

		printf("%.3lf\n",radius_in / square(radius_cir));
	}

	return 0;
}
