#include <cstdio>

int josephus(int n, int m)
{
    int last = 0;
    for(int i = 2; i <= n; i++)
        last = (last + m) % i;
    return last;
}

int main(void)
{  
    int n;
    while(scanf("%d", &n) != EOF && n != 0)
    {
        for(int m = 2; ; m++)
        {
            if(josephus(n - 1, m) == 0)
            {
                printf("%d\n", m);
                break;
            }
        }
    }
    return 0;
}
