/*Time Limit Exceeded*/
#include <stdio.h>
#include <math.h>

int main()
{
	int mod;
	int i,x;
	
	while(scanf("%d",&mod) != EOF)
	{
		if(mod % 2 && mod != 1)
		{
			i = 1;
			x = 2;
			while(x % mod != 1)
			{
				if(x > mod)
					x %= mod;
				else
				{
					x *= 2;
					i++;
				}
			}
			printf("2^%d mod %d = 1\n",i,mod);
		}
		else
			printf("2^? mod %d = 1\n",mod);
		
	}
	
	return 0;
}
