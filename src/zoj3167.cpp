#include <iostream>
#include <string>

using namespace std;

const int LENGTH = 512;

void initBigInteger(int b[])	// init to 1
{
	b[0] = 1;
	for(int i = 1; i < LENGTH; i++)
		b[i] = 0;
}

void multBigInteger(int b[], int m)
{
	for(int i = 0; i < LENGTH; i++)
		b[i] *= m;
	for(int i = 0; i < LENGTH; i++)
	{
		b[i + 1] += b[i] / 10;
		b[i] %= 10;
	}
}

int main()
{
	int k, m, n;
	int product[LENGTH];

	while(cin >> k >> m)
	{
		initBigInteger(product);
		for(n = 1; n <= 100; n++)
		{
			multBigInteger(product, m);
			if(product[k - 1] == 7)
				break;
		}
		cout << n << endl;
	}
}
