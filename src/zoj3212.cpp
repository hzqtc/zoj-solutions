#include <cstdio>

using namespace std;

int main()
{
    int t;
    int n, m, k;
    const int MAX = 16;
    int matrix[MAX][MAX];
    int i, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &k);
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                matrix[i][j] = 1;
        for(i = 1; i < n - 1; i++)
        {
            for(j = 1; j < m - 1; j++)
            {
                if(k == 0)
                    break;
                matrix[i][j] = 0;
                matrix[i - 1][j] = 0;
                matrix[i + 1][j] = 0;
                matrix[i][j - 1] = 0;
                matrix[i][j + 1] = 0;
                k--;
            }
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(j == 0)
                    printf("%d", matrix[i][j]);
                else if(j == m - 1)
                    printf(" %d\n", matrix[i][j]);
                else
                    printf(" %d", matrix[i][j]);
            }
        }
    }
    return 0;
}
