#include <cstdio>
#include <map>

using namespace std;

int main()
{
	const int MAX = 100000;
	int num[MAX];
	int count;
	
	while(scanf("%d",&count) , count > 0)
	{
		int i;
		map<int,int> m;
		for(i=0;i<count;i++)
		{
			scanf("%d",num + i);
			m[num[i]] = i + 1;
		}
		for(i=1;i<=count;i++)
		{
			if(m[i] != num[i - 1])
				break;
		}
		if(i > count)
			puts("ambiguous");
		else
			puts("not ambiguous");
	}
	
	return 0;
}

