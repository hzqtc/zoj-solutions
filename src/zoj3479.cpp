#include <cstdio>

int main()
{
    int t, n;
    const char* shengxiao[] = { "Rat", "Ox", "Tiger", "Rabbit", "Dragon",
        "Snake", "Horse", "Ram", "Monkey", "Rooster", "Dog", "Pig" };
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        n = 4 - (n - 1) % 12;
        if(n <= 0)
            n += 12;
        printf("%s\n", shengxiao[n - 1]);
    }
    return 0;
}
