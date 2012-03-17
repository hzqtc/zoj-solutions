#include <iostream>
#include <string>

using namespace std;

bool cocacola(int i)
{
	if(i % 7 == 0)
		return true;
	else
	{
		while(i)
		{
			if(i % 10 == 7)
				return true;
			i /= 10;
		}
		return false;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, i;
		cin >> n;
		for(i = 7, m = 0; ; i++)
		{
			if(cocacola(i))
			{
				if(++m == n)
					break;
			}
			else
				m = 0;
		}
		cout << i - n + 1 << endl;
	}
	return 0;
}
