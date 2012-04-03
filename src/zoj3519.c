#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n, caocao;
    int opponents[512];
    int defeat[512];
    int i;

    while(scanf("%d %d", &n, &caocao) != EOF)
    {
        for(i = 0; i < n; i++)
            scanf("%d", &opponents[i]);
        memset(defeat, 0, sizeof(defeat));
        qsort(opponents, n, sizeof(int), cmp);
        for(i = 0; i < n; i++)
        {
            if(opponents[i] > caocao)
            {
                caocao += 2;
                defeat[i] = 1;
            }
        }
        for(i = 0; i < n; i++)
        {
            if(defeat[i] == 0)
                caocao += 1;
        }
        printf("%d\n", caocao);
    }
    return 0;
}
