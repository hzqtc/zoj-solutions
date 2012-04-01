#include <stdio.h>

int main()
{
    char c;
    char lastc;
    int len = 0;

    while((c = getchar()) != EOF)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if(len == 0)
                putchar(c);
            len++;
            lastc = c;
        }
        else
        {
            if(len > 2)
                printf("%d", len - 2);
            if(len > 1)
                putchar(lastc);
            putchar(c);

            len = 0;
        }
    }
    return 0;
}
