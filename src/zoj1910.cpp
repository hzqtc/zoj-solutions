#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int casecount,n;
	int a,b,c;
	int area,t;

	scanf("%d",&casecount);
	while(casecount--)
	{
		scanf("%d",&n);
		area = -1;
		for(a=1;a*a*a<=n;a++)
		{
			for(b=1;a*b*b<=n;b++)
			{
				if(n % (a * b) == 0)
				{
					c = n / a / b;
					t = 2 * (a * b + b * c + c * a);
					if(area == -1 || t < area)
						area = t;
				}
			}
		}
		printf("%d\n",area);
	}

	return 0;
}