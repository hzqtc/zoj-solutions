#include <stdio.h>
#include <string.h>

int main()
{
    char line[4200];
    int num;
    int i, j, len;

    while(gets(line) != NULL)
    {
        len = strlen(line);
        num = 0;
        j = 0;
        for(i = 0; i < len; i++)
        {
            if(i == 0)
                printf("%04x:", num);
            else if(i % 16 == 0)
            {
                putchar(' ');
                for(; j < i; j++)
                {
                    if(line[j] >= 'a' && line[j] <= 'z')
                        putchar(line[j] - 'a' + 'A');
                    else if(line[j] >= 'A' && line[j] <= 'Z')
                        putchar(line[j] - 'A' + 'a');
                    else
                        putchar(line[j]);
                }
                putchar('\n');
                num += 16;
                printf("%04x:", num);
            }
            if(i % 2 == 0)
                printf(" %x", line[i]);
            else
                printf("%x", line[i]);
        }
        if(j < i)
        {
            int k;
            for(k = 0; (i + k) % 16 > 0; k++)
            {
                if((i + k) % 2 == 0)
                    printf("   ");
                else
                    printf("  ");
            }
            putchar(' ');
            for(; j < i; j++)
            {
                if(line[j] >= 'a' && line[j] <= 'z')
                    putchar(line[j] - 'a' + 'A');
                else if(line[j] >= 'A' && line[j] <= 'Z')
                    putchar(line[j] - 'A' + 'a');
                else
                    putchar(line[j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
