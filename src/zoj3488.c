#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t;
    double a, b, c, d, e, f;
    const double eps = 1e-8;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
        if(fabs(a - c) < eps)
            puts("circle");
        else if(a * c < -eps)
            puts("hyperbola");
        else if(a * c > eps)
            puts("ellipse");
        else
            puts("parabola");
    }
    return 0;
}
