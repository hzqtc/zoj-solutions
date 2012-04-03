#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int minWeight, maxWeight;
} soldier;

int cmpSoldier(const void* a, const void* b)
{
    return ((soldier*)a)->maxWeight - ((soldier*)b)->maxWeight;
}

int cmpInt(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findFirstLE(int* array, int n, int x)
{
    int low = 0, high = n - 1;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    soldier soldiers[2500];
    int weapons[40000];
    int taken[40000];
    int n, m;
    int i;
    int armed;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(i = 0; i < n; i++)
            scanf("%d %d", &soldiers[i].minWeight, &soldiers[i].maxWeight);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &weapons[i]);
            taken[i] = 0;
        }
        qsort(soldiers, n, sizeof(soldier), cmpSoldier);
        qsort(weapons, m, sizeof(int), cmpInt);

        armed = 0;
        for(i = 0; i < n; i++)
        {
            int w = findFirstLE(weapons, m, soldiers[i].minWeight);
            for(; w < m && weapons[w] <= soldiers[i].maxWeight; w++)
            {
                if(taken[w] == 0)
                {
                    armed++;
                    taken[w] = 1;
                    break;
                }
            }
        }
        printf("%d\n", armed);
    }
    return 0;
}
