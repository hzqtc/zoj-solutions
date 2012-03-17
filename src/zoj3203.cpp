#include <cstdio>

#define eps 0.0000001

double len(double x, double H, double h, double D)
{
    double boundary = h * D / H;
    if(x < boundary)
        return (D * h - x * H) / (D - x) + x;
    else
        return h * (D - x) / (H - h);
}

int main()
{
    double h, H, D;
    int n;

    scanf("%d", &n);
    while(n--)
    {
        double l, r, lm, rm;
        scanf("%lf %lf %lf", &H, &h, &D);
        l = 0;
        r = D;
        while(r - l >= eps)
        {
            lm = (r - l) / 3 + l;
            rm = r - (r - l) / 3;
            if(len(lm, H, h, D) >= len(rm, H, h, D))
                r = rm;
            else
                l = lm;
        }
        printf("%.3lf\n", len(l, H, h, D));
    }
    
    return 0;
}
