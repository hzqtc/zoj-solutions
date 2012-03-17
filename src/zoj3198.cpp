#include <cstdio>

int main()
{
    int t, s1, s2;
    const int size = 200000;
    int a1[size], a2[size];
    int i, j, count;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &s1);
        for(i = 0; i < s1; i++)
            scanf("%d", &a1[i]);
        scanf("%d", &s2);
        for(i = 0; i < s2; i++)
            scanf("%d", &a2[i]);

        for(i = 0, j = 0, count= 0; i < s1 && j < s2; )
        {
            if(a1[i] == a2[j])
            {
                i++;
                j++;
                count++;
            }
            else if(a1[i] > a2[j])
                j++;
            else
                i++;
        }
        printf("%d\n", count);
    }

    return 0;
}
