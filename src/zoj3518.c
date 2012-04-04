#include <stdio.h>
#include <string.h>

int points[10000000];

int main()
{
    int l, n1, n2;
    int x, y;
    int i, j;
    int len, maxlen;

    while(scanf("%d %d %d", &l, &n1, &n2) != EOF)
    {
        memset(points, 0, l * sizeof(int));
        for(i = 0; i < n1 + n2; i++)
        {
            scanf("%d %d", &x, &y);
            for(j = x; j <= y; j++)
                points[j]++;
        }

        len = 0;
        maxlen = 0;
        for(j = 0; j < l; j++)
        {
            if(points[j] == 1)
                len++;
            else
            {
                if(len > maxlen)
                    maxlen = len;
                len = 0;
            }
        }
        if(len > maxlen)
            maxlen = len;
        printf("%d\n", maxlen);
    }
    return 0;
}
