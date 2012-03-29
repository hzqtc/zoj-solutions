#include <cstdio>
#include <cstdlib>

int cmpDouble(const void* a, const void* b)
{
    return *(double*)a - *(double*)b;
}

int main()
{
    int t;
    int n;
    double a[512];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%lf", &a[i]);
        qsort(a, n, sizeof(double), cmpDouble);
        if(n % 2 == 0)
            printf("%.3lf\n", (a[n / 2 - 1] + a[n / 2]) / 2);
        else
            printf("%.3lf\n", a[n / 2]);
    }
    return 0;
}
