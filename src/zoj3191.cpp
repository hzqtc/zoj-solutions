#include <cstdio>

int main()
{
    int d;
    int h, h2;
    while(scanf("%d", &d) && d >= 0)
    {
        h = (15 - d / 30) % 12;
        if(d % 30)
        {
            h2 = (h - 1) % 12;
            if(h2 < 0)
                h2 += 12;
            printf("Between %d o'clock and %d o'clock\n", h2, h);
        }
        else
            printf("Exactly %d o'clock\n", h);
    }
    return 0;
}
