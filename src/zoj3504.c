#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct
{
    double real, imag;
} complex;

double modulus(complex* c)
{
    return sqrt(c->real * c->real + c->imag * c->imag);
}

int main()
{
    char line[256];
    char* pos;
    complex nums[32];
    int n, i;
    double p, pnorm;

    while(gets(line) != NULL)
    {
        n = 0;
        pos = line;
        while(sscanf(pos, "(%lf,%lf)", &nums[n].real, &nums[n].imag))
        {
            n++;
            if((pos = strchr(pos, ' ')) == NULL)
                break;
            else
                pos++;
        }

        gets(line);
        pos = line;
        while(sscanf(pos, "(%lf,%lf)", &nums[n].real, &nums[n].imag))
        {
            n++;
            if((pos = strchr(pos, ' ')) == NULL)
                break;
            else
                pos++;
        }

        scanf("%lf\n", &p);

        pnorm = 0;
        for(i = 0; i < n / 2; i++)
        {
            double real = nums[i].real - nums[i + n / 2].real;
            double imag = nums[i].imag - nums[i + n / 2].imag;
            pnorm += pow(sqrt(real * real + imag * imag), p);
        }
        printf("%.8lf\n", pow(pnorm, 1 / p));
    }
    return 0;
}
