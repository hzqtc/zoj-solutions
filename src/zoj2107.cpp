/* Author: »ÆÖÇÇ¿; ID: 3061101100; No.1 
 * Description: Bonus 1 Source Code.
 * Date: 2007.12.23
 */
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

class point
{
public:
	point(): x(0), y(0), distance(0) {}
	point(double ix, double iy): x(ix), y(iy)
	{
		distance = sqrt(x * x + y * y);
	}
	void setxy(double ix, double iy)
	{
		x = ix;
		y = iy;
		distance = sqrt(x * x + y * y);
	}
	double dis(const point& p)
	{
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y- p.y));
	}
	double x, y;
	double distance;
};

int pointcmp(const void* a, const void* b)
{
	return ((point*)a)->distance > ((point*)b)->distance;
}

const int MAX = 100000;
point p[MAX];

int main()
{
	int n;
	int i, j;
	double x, y;

	while(scanf("%d", &n), n > 0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf", &x, &y);
			p[i].setxy(x, y);
		}
		qsort(p, n, sizeof(point), pointcmp);
		double min = p[0].dis(p[1]);
		double tmp;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(p[j].distance - p[i].distance > min)
					break;
				else
				{
					if((tmp = p[j].dis(p[i])) < min)
						min = tmp;
				}
			}
		}
		printf("%.2lf\n", min / 2);
	}

	return 0;
}
