#include <cstdio>

using namespace std;

int GetMod(int a, int b, int m);

int main()
{
	int caseCount;
	scanf("%d", &caseCount);
	while(caseCount--)
	{
		int sum = 0;
		int m, line;
		scanf("%d %d", &m, &line);
		int a, b;
		while(line--)
		{
			scanf("%d %d", &a, &b);
			a %= m;
			sum += GetMod(a, b, m);
			sum %= m;
		}
		printf("%d\n", sum);
	}

	return 0;
}

int GetMod(int a, int b, int m)
{
	if(b == 0)
		return 1;

	if((b >> 1) << 1 == b)		// even number
	{
		int t = GetMod(a, b / 2, m);
		return (t * t) % m;
	}
	else						// odd number
	{
		int t = GetMod(a, b / 2, m);
		return (((t * t) % m) * a) % m;
	}
}
