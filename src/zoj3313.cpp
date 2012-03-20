#include <cstdio>
#include <cmath>

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        double h = 0, m = 0;
        int count = 0;
        for(int i = 0; i < 24 * 3600; i++)
        {
            h += 360.0 / 3600 / 12; // the hour hand
            m += 360.0 / 3600;      // the minute hand
            if(h > 360)
                h -= 360;
            if(m > 360)
                m -= 360;
            double angle = fabs(m - h);
            if(angle > 180)
                angle = 360 - angle;
            if(angle <= x)
                count++;
        }
        printf("%.2f\n", (double)count);
    }
    return 0;
}
