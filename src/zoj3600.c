#include <stdio.h>

int main()
{
    int n;
    int d, t;
    double priceA, priceB;

    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &d, &t);

        priceA = priceB = 11;
        if (d > 10) {
            priceA += (d - 10) * 3;
            priceB += (d - 10) * 3.75;
            d = 10;
        }
        if (d > 3) {
            priceA += (d - 3) * 2;
            priceB += (d - 3) * 2.5;
        }
        priceA += t * 2.0 / 5;
        priceB += t * 2.5 / 4;

        printf("%d\n", (int)(0.5 + priceB) - (int)(0.5 + priceA));
    }

    return 0;
}
