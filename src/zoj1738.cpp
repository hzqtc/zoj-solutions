#include <cstdio>

using namespace std;

const int MAX = 32768;
int count[MAX];

int main()
{
	int num;
	int a,b,c,d;

	for(a=1;a * a < MAX;a++)
	{
		count[a * a]++;
	}
	for(a=1;a * a < MAX;a++)
	{
		for(b=a;a * a + b * b < MAX;b++)
		{
			count[a * a + b * b]++;
		}
	}
	for(a=1;a * a < MAX;a++)
	{
		for(b=a;a * a + b * b < MAX;b++)
		{
			for(c=b;a * a + b * b + c * c < MAX;c++)
			{
				count[a * a + b * b + c * c]++;
			}
		}
	}
	for(a=1;a * a < MAX;a++)
	{
		for(b=a;a * a + b * b < MAX;b++)
		{
			for(c=b;a * a + b * b + c * c < MAX;c++)
			{
				for(d=c;a * a + b * b + c * c + d * d < MAX;d++)
				{
					count[a * a + b * b + c * c + d * d]++;
				}
			}
		}
	}

	while(scanf("%d",&num) , num != 0)
	{
		printf("%d\n",count[num]);
	}

	return 0;
}