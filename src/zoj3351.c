#include <stdio.h>

int main()
{
    int n;
    while(scanf("%*d%*d%d", &n) != EOF)
        printf("%d\n", n);
    return 0;
}
