#include <cstdio>

using namespace std;

bool check(int x,int p);

int main()
{
	int x,p;
	bool fail;
	
	while(scanf("%d",&x) , x >= 0)
	{
		p = x - 1;
		fail = false;
		while(!check(x,p))
		{
			p--;
			if(p <= 1)
			{
				fail = true;
				break;
			}
		}
		if(fail == true)
			printf("%d coconuts, no solution\n",x);
		else
			printf("%d coconuts, %d people and 1 monkey\n",x,p);
	}
	
	return 0;
}

bool check(int x,int p)
{
	if(p <= 0)
		return false;
	for(int i = 1;i<=p;i++)
	{
		if(x % p == 1)
		{
			x -= 1;
			x -= x / p;
		}
		else
			return false;
	}
	if(x % p == 0)
		return true;
	else
		return false;
}
/*
3
25
30
765
3121
233275
823537
-1
*/
