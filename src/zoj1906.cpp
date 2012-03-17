#include <cstdio>
#include <cmath>

int prime(long n)
{
	int k,i;
	k=sqrt((double)n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
			return 0;
	}
	return n;
}

int main()
{
	int i, n, temp, count;

	while(scanf("%ld", &n) != EOF && n)
	{
		if(prime(n))
		{
			printf("%ld\n", n-1);
			continue;
		}
		count = n;
		if(n % 2 == 0)
			count /= 2;
		temp = n;
		for(i = 3; i <= temp; i += 2)
		{
			if(temp % i == 0)
			{
				while(temp % i == 0)
					temp /= i;
				count = count / i * (i - 1);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
