#include <iostream>

using namespace std;

int main()
{
	const int MAX = 64;
	int original[MAX];
	int result [MAX];
	int n, i, j;
	char cmd;
	while(cin >> n, n > 0)
	{
		cin >> cmd;
		for(i = 0; i < n; i++)
		{
			cin >> original[i];
			result[i] = 0;
		}
		if(cmd == 'P')
		{
			for(i = 0; i < n; i++)
			{
				for(j = 0; j < i; j++)
				{
					if(original[j] > original[i])
						result[original[i] - 1]++;
				}
			}
		}
		else if(cmd == 'I')
		{
			int empty = 0;
			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(result[j] == 0)
					{
						if(empty == original[i])
						{
							result[j] = i + 1;
							empty = 0;
							break;
						}
						else
							empty++;
					}
				}
			}
		}
		for(i = 0; i < n; i++)
		{
			if(i > 0)
				cout << ' ';
			cout << result[i];
		}
		cout << endl;
	}

	return 0;
}
