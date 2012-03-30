#include <stdio.h>
#include <string.h>

int main()
{
    int t, n;
    int problems[10000];
    int maxCount;
    int maxId;
    int id;

    scanf("%d", &t);
    while(t--)
    {
        memset(problems, 0, sizeof(problems));
        maxCount = maxId = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &id);
            problems[id]++;
            if(problems[id] > maxCount || (problems[id] == maxCount && id > maxId))
            {
                maxCount = problems[id];
                maxId = id;
            }
        }
        printf("%d\n", maxId);
    }
    return 0;
}
