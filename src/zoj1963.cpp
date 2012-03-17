#include <cstdio>

using namespace std;

int foo(double d);

int main()
{
	char time[8];
	int h,m,s;
	int total_sec;
	int section;
	int teamnumber;
	double distance;
	bool null;
	
	scanf("%d %lf",&section,&distance);
	
	while(scanf("%d",&teamnumber) != EOF)
	{
		null = false;
		total_sec = 0;
		for(int i = 0;i<section;i++)
		{
			scanf("%s",time);
			if(time[0] == '-')
				null = true;
			else
			{
				sscanf(time,"%d:%d:%d",&h,&m,&s);
				total_sec += h * 3600 + m * 60 + s;
			}
		}
		if(null == true)
			printf("%3d: -\n",teamnumber);
		else
		{
			double total_persec = (double)total_sec / distance;
			int permin = (int)(total_persec / 60);
			int persec = foo(total_persec - permin * 60);
			while(persec >= 60)
			{
				permin++;
				persec -= 60;
			}
			printf("%3d: %d:%02d min/km\n",teamnumber,permin,persec);
		}
	}
	
	return 0;
}

int foo(double d)
{
	if((int)(d * 10) % 10 < 5)
		return (int)d;
	else
		return (int)d + 1;
}

