#include <cstdio>

using namespace std;

int main()
{
    int n, s;
    char line[8];
    int ans[8];
    int i, j;
    while(scanf("%d\n", &n) != EOF)
    {
        for(j = 0; j < 7; j++)
            ans[j] = 0;

        s = 2 * n - 1;
        for(i = 0; i < s; i++)
        {
            gets(line);
            for(j = 0; j < 7; j++)
                ans[j] ^= line[j];
        }
        
        for(j = 0; j < 7; j++)
            putchar(ans[j]);
        putchar('\n');
    }
    return 0;
}
