#include <cstdio>

using namespace std;

int main()
{
	int a,b,n;
	const int MAX = 1000;
	int fn[MAX];
	int cycle,cyclestart;
	int i;

	while(scanf("%d %d %d",&a,&b,&n) , n > 0)
	{
		a %= 7;
		b %= 7;
		cycle = -1;
		fn[0] = fn[1] = 1;
		for(i = 2;i<n;i++)
		{
			fn[i] = (a * fn[i - 1] + b * fn[i - 2]) % 7;
			for(cyclestart=1;cyclestart<i;cyclestart++)
			{
				if(fn[i] == fn[cyclestart] && fn[i - 1] == fn[cyclestart - 1])
				{
					cycle = i - cyclestart;
					cyclestart--;
					break;
				}
			}
			if(cycle > 0)
				break;
		}
		if(i >= n)
			printf("%d\n",fn[n - 1]);
		else
		{
			if((n - cyclestart) % cycle)
				printf("%d\n",fn[(n - cyclestart) % cycle + cyclestart - 1]);
			else
				printf("%d\n",fn[cyclestart + cycle - 1]);
		}
	}

	return 0;
}
