#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	const double pi = 3.14159265358979323846;
	double h, a, b;
	double angle, k;
	double x, y;

	while(scanf("%lf %lf %lf %lf", &angle, &h, &a, &b) != EOF)
	{
		k = -tan(angle / 180 * pi);
		x = 2 * (k * a - k * h) / (k * k + 1);
		y = 2 * (k * k * a + h) / (k * k + 1) - a;
		double distance = sqrt((x - b) * (x - b) + y * y);
		printf("%.2lf\n", distance);
	}
	return 0;
}
