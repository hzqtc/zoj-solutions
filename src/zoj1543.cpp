#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int cmp(const void * a,const void * b);

int main()
{
    int count,i;
    const int MAX = 110;
    int num[MAX];
    double minwei;

    while(scanf("%d",&count) != EOF)
    {
		for(i=0;i<count;i++)
		{
			scanf("%d",&num[i]);
		}
		qsort(num,count,sizeof(int),cmp);
		minwei = num[count - 1];
		for(i=count-2;i>=0;i--)
		{
			minwei = sqrt(minwei * num[i]) * 2;
		}
		printf("%.3lf\n",minwei);
	}

    return 0;
}

int cmp(const void * a,const void * b)
{
    return *(int *)a - *(int *)b;
}
