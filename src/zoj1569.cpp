#include <cstdio>

using namespace std;

int main()
{
	const int MAX = 10000;
	int n,m;
	int num;
	int sum[MAX];
	int count;
	int i,j;

	while(scanf("%d %d",&n,&m) != EOF)
	{
		scanf("%d",&sum[0]);
		sum[0] %= m;
		for(i=1;i<n;i++)
		{
			scanf("%d",&num);

			sum[i] = sum[i - 1] + num;
			sum[i] %= m;
		}

		count = 0;
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(sum[i] == sum[j])
					count++;
			}
		}
		for(i=0;i<n;i++)
		{
			if(sum[i] % m == 0)
				count++;
		}
		printf("%d\n",count);
	}

	return 0;
}
