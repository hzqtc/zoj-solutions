#include <cstdio>

int countBits(int i)
{
    int n = 0;
    while(i > 0)
    {
        n += (i & 1);
        i >>= 1;
    }
    return n;
}

int main()
{
    int t;
    int m, n;
    int a[128], b[128];
    int i, j;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &b[i]);

        for(i = 0; i < n; i++)
        {
            int minBits = 32, diffBits, num;
            for(j = 0; j < m; j++)
            {
                diffBits = countBits(b[i] ^ a[j]);
                if(diffBits < minBits || (diffBits == minBits && a[j] < num))
                {
                    minBits = diffBits;
                    num = a[j];
                }
            }
            printf("%d\n", num);
        }
    }
    return 0;
}
