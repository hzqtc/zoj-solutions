#include <cstdio>

using namespace std;

const int MAX = 1024;
double dp[MAX][MAX];

int main()
{
	int i, j;
	for(i = 0; i < MAX; i++)
		dp[i][0] = dp[0][i] = 0;
	for(i = 1; i < MAX; i++)
		for(j = 1; j < MAX; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * 0.5 + 1;

	int n;
	int caseCount;
	scanf("%d", &caseCount);
	while(caseCount--)
	{
		scanf("%d", &n);
		printf("%.2lf\n", dp[n][n]);
	}

	return 0;
}
