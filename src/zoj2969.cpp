#include <iostream>

using namespace std;

const int MAX = 128;
int c[MAX];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n;
		for(int i = n; i >= 0; i--)
		{
			cin >> m;
			c[i] = m;
		}
		bool put = false;
		if(n == 0)
			cout << 0 << endl;
		else
		{
			for(int i = n; i > 0; i--)
			{
				if(put == false)
				{
					cout << c[i] * i;
					put = true;
				}
				else
					cout << ' ' << c[i] * i;
			}
			cout << endl;
		}
	}

	return 0;
}