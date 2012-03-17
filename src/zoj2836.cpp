#include <iostream>
#include <set>

using namespace std;

int getGCD(int a, int b);
int count_less(int max, int s[], int n);

int main()
{
	int n, m;
	int num[10];
	int i;

	while(cin >> n >> m)
	{
		int lcm = 1;
		for(i=0;i<n;i++)
		{
			cin >> num[i];
			lcm = lcm * num[i] / getGCD(num[i], lcm);
		}
		
		set<int> foo;
		for(i=0;i<n;i++)
		{
			for(int k = num[i];k<=lcm;k+=num[i])
				foo.insert(k);
		}

		int re = m / lcm * foo.size();
		m %= lcm;
		set<int>::iterator iter = foo.begin();
		while(iter != foo.end())
		{
			if(*iter++ <= m)
				re++;
		}

		cout << re << endl;
	}

	return 0;
}

int getGCD(int a, int b)
{
	while(b)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
/*
3 2
2 3 7
3 6
2 3 7
2 10
2 3
3 50
2 3 7
*/
