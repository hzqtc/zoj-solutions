#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	const int MAX = 256;
	int d[MAX];
	while(scanf("%d", &n), n > 0)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", d + i);
		for(int i = 2; i <= n; i *= 2)
		{
			vector<int> tmp;
			for(int j = 0; j < i / 2; j++)
			{
				int sum = d[j];
				int differ = d[j + i / 2];
				tmp.push_back((sum + differ) / 2);
				tmp.push_back((sum - differ) / 2);
			}
			for(int j = 0; j < tmp.size(); j++)
				d[j] = tmp[j];
		}
		for(int i = 0; i < n; i++)
		{
			if(i != 0)
				printf(" %d", d[i]);
			else
				printf("%d", d[i]);
		}
		putchar('\n');
	}
	return 0;
}
