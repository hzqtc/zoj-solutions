#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b? a: b;
}

int main()
{
    int n;
    int atoms[10][10];
    int dp[1 << 10];
    int i, j;
    int status;
    int ans;

    while(scanf("%d", &n) && n > 0)
    {
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%d", &atoms[i][j]);

        memset(dp, 0, sizeof(dp));
        for(status = 0; status < (1 << n); status++)
        {
            for(i = 0; i < n; i++)
            {
                if((status & (1 << i)) != 0)
                    continue;
                for(j = 0; j < n; j++)
                {
                    if(j != i && (status & (1 << j)) == 0)
                        dp[status | (1 << i)] = max(dp[status | (1 << i)], dp[status] + atoms[j][i]);
                }
            }
        }

        ans = 0;
        for(status = 0; status < (1 << n); status++)
        {
            if(dp[status] > ans)
                ans = dp[status];
        }
        printf("%d\n", ans);
    }
    return 0;
}
