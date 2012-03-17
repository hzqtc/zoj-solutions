#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	typedef long long lint;
	lint num,i,upbond;

	while(scanf("%lld",&num) , num > 0)
	{
		i = 2;
		upbond = (lint)sqrt((double)num);
		while(num >= i && i <= upbond)
		{
			if(num % i)
			{
				if(i == 2)
					i++;
				else
					i += 2;
			}
			else
			{
				printf("%lld\n",i);
				num /= i;
				upbond = (lint)sqrt((double)num);
			}
		}
		printf("%lld\n",num);
		putchar('\n');
	}

	return 0;
}