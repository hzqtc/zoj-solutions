#include <cstdio>

int main()
{
    int a, b, c;
    int n;

    while(scanf("%d", &n) != EOF)
    {
        a = n / 100;
        b = (n / 10) % 10;
        c = n % 10;
        if(a * a * a + b * b * b + c * c * c == n)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
