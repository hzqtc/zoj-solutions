#include <stdio.h>

int main()
{
    const char* stems[] = { "Jia", "Yi", "Bing", "Ding", "Wu", "Ji", "Geng", "Xin", "Ren", "Gui" };
    const char* branches[] = { "zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai" };
    int n;
    int year, distance;
    int a, b;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &year);
        if(year < 1911)
        {
            distance = (1911 - year) % 60;
            /*the year before 1AD is 1BC, no year 0*/
            if(year < 0)
                distance -= 1;
            a = (-distance + 7) % 10;
            if(a < 0)
                a += 10;
            b = (-distance + 11) % 12;
            if(b < 0)
                b += 12;
        }
        else
        {
            distance = (year - 1911) % 60;
            a = (distance + 7) % 10;
            b = (distance + 11) % 12;
        }
        printf("%s%s\n", stems[a], branches[b]);
    }
    return 0;
}
