#include <cstdio>

using namespace std;

int gcd(int m,int n);
void init();

const int MAX = 1010;
int num[MAX];

int main()
{
	int casecount,caseindex;
	int size;
	
	init();
	
	scanf("%d",&casecount);
	for(caseindex=1;caseindex<=casecount;caseindex++)
	{
		scanf("%d",&size);
		printf("%d %d %d\n",caseindex,size,num[size]);
	}
	
	return 0;
}

int gcd(int m,int n)
{
	int c;
	if(m == 0)
		return n;
	else if(n == 0)
		return m;
	while(c = m % n)
	{
		m = n;
		n = c;
	}
	return n;
}

void init()
{
	num[0] = 0;
	num[1] = 3;
	for(int i = 2;i<=1000;i++)
	{
		num[i] = num[i - 1];
		for(int j = 0;j<i;j++)
		{
			if(gcd(i,j) == 1)
				num[i] += 2;
		}
	}
}

