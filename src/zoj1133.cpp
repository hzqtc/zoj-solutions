#include <cstdio>

using namespace std;

bool test(int);
int sum_digits(int);

int main()
{
	int min,num;

	while(scanf("%d",&min) , min > 0)
	{
		num = min + 1;
		while(test(num) == false)
			num++;
		printf("%d\n",num);
	}
}

int sum_digits(int n)
{
	int sum = 0;

	while(n)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

bool test(int n)
{
	int n_copy = n,digit_sum = 0;

	for(int i = 2;i * i <= n;i == 2 ? i++ : i += 2)
	{
		while(n % i == 0 && n > i)
		{
			digit_sum += sum_digits(i);
			n /= i;
		}
	}
	if(n == n_copy)
		return false;//it's a prime number

	if(n > 1)
		digit_sum += sum_digits(n);

	return digit_sum == sum_digits(n_copy);
}

