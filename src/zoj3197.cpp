#include <cstdio>
#include <cstdlib>

typedef struct
{
    int a, b;
} range;

int rangecmp(const void* x, const void* y)
{
    return ((range*)x)->a - ((range*)y)->a;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int start = 1, end = n + 1;
        int i, count = 0;

        range queries[8192];
        for(i = 0; i < n; i++)
            scanf("%d %d", &queries[i].a, &queries[i].b);
        qsort(queries, n, sizeof(range), rangecmp);

        i = 0;
        while(start < end)
        {
            range* max = &queries[i];
            while(queries[i].a <= start)
            {
                if(queries[i].b > max->b)
                    max = &queries[i];
                i++;
            }
            count++;
            start = max->b + 1;
        }
        printf("%d\n", count);
    }
    return 0;
}
