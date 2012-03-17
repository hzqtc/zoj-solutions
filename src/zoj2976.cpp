#include <cstdio>
#include <cmath>

using namespace std;

struct Light
{
	int x, y, z;
	int i;
}light[128];


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		int x1 = 100, y1 = 100, x2 = -100, y2 = -100;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d %d", &light[i].x, &light[i].y, &light[i].z, &light[i].i);
			if(light[i].x < x1)
				x1 = light[i].x;
			if(light[i].x > x2)
				x2 = light[i].x;
			if(light[i].y < y1)
				y1 = light[i].y;
			if(light[i].y > y2)
				y2 = light[i].y;
		}
		double max = 0;
		for(int x = x1; x <= x2; x++)
		{
			for(int y = y1; y <= y2; y++)
			{
				double tmp = 0;
				for(int i = 0; i < n; i++)
				{
					double r2 = (light[i].x - x) * (light[i].x - x) + (light[i].y - y) * (light[i].y - y) + light[i].z * light[i].z;
					tmp += light[i].i * light[i].z / r2 / sqrt(r2);
				}
				if(tmp > max)
					max = tmp;
			}
		}
		printf("%.2lf\n", max);
	}
	return 0;
}
