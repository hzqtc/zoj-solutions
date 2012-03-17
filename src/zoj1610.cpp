#include <cstdio>

using namespace std;

int main()
{
	const int MAX = 8001;
	int segment[MAX];
	int segcount,i;
	int x1,x2,color;
	int c[MAX];
	int temp;

	while(scanf("%d",&segcount) != EOF)
	{
		for(i=0;i<MAX;i++)
		{
			segment[i] = -1;
		}
		for(i=0;i<segcount;i++)
		{
			scanf("%d %d %d",&x1,&x2,&color);
			for(int j = x1;j < x2;j++)
			{
				segment[j] = color;
			}
		}

		for(i=0;i<MAX;i++)
		{
			c[i] = 0;
		}
		i = 0;
		while(i < MAX)
		{
			if((temp = segment[i++]) != -1)
			{
				c[temp]++;
				while(segment[i] == temp)
				{
					i++;
				}
			}
		}

		for(i=0;i<MAX;i++)
		{
			if(c[i] > 0)
			{
				printf("%d %d\n",i,c[i]);
			}
		}
		putchar('\n');
	}

	return 0;
}
