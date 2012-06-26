#include <stdio.h>

int gcd(int a, int b)
{
    int c;
    while (c = a % b) {
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int t;
    int a, m, x;
    int i;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &m);
        if (m == 1) {
            printf("1\n");
        }
        else if (gcd(a, m) != 1)
        {
            printf("Not Exist\n");
        }
        else {
            for (i = 1; (a * i) % m != 1; i++)
                ;
            printf("%d\n", i);
        }
    }

    return 0;
}
