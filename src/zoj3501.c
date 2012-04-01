#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int dec;
    char roman[16];
} number;

int cmpNumber(const void* a, const void* b)
{
    return strcmp(((number*)a)->roman, ((number*)b)->roman);
}

void setRoman(number* num)
{
    const char* thousands[] = { "M", "MM", "MMM" };
    const char* hundreds[] = { "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    const char* tens[] = { "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    const char* ones[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

    int thousand = (num->dec / 1000) % 10;
    int hundred = (num->dec / 100) % 10;
    int ten = (num->dec / 10) % 10;
    int one = num->dec % 10;

    memset(num->roman, '\0', sizeof(num->roman));
    if(thousand > 0)
        strcpy(num->roman + strlen(num->roman), thousands[thousand - 1]);
    if(hundred > 0)
        strcpy(num->roman + strlen(num->roman), hundreds[hundred - 1]);
    if(ten > 0)
        strcpy(num->roman + strlen(num->roman), tens[ten - 1]);
    if(one > 0)
        strcpy(num->roman + strlen(num->roman), ones[one - 1]);
}

int main()
{
    int t, n;
    number nums[10000];
    int i;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &nums[i].dec);
            setRoman(&nums[i]);
        }
        qsort(nums, n, sizeof(number), cmpNumber);
        for(i = 0; i < n; i++)
        {
            if(i > 0)
                printf(" %d", nums[i].dec);
            else
                printf("%d", nums[i].dec);
        }
        printf("\n");
    }
    return 0;
}

