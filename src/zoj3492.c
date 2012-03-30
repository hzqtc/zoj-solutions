#include <stdio.h>
#include <string.h>

int main()
{
    int t, n;
    char children[128][32];
    char frontChild[32];
    int front, behind;
    int i;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        scanf("%s", frontChild);
        for(i = 0; i < n; i++)
        {
            scanf("%s", children[i]);
            if(strcmp(children[i], frontChild) == 0)
                front = i;
        }
        behind = (front + (n / 2)) % n;
        printf("%s\n", children[behind]);
    }
    return 0;
}
