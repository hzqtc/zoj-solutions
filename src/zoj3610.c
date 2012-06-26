#include <stdio.h>

int main()
{
    int t;
    char b[32], g[32], x[32];
    
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s %s", b, g, x);
        printf("%s will survive\n", g);
    }

    return 0;
}
