#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n, m, p;
	while(cin >> n >> m >> p)
	{
		map<char, int> alpha;
		char c;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> c;
				alpha[c]++;
			}
		}
		string line;
		for(int i = 0; i < p; i++)
		{
			cin >> line;
			int len = line.length();
			for(int j = 0; j < len; j++)
				alpha[line[j]]--;
		}
		for(map<char, int>::iterator iter = alpha.begin(); iter != alpha.end(); iter++)
		{
			if(iter->second > 0)
				cout << string(iter->second, iter->first);
		}
		cout << endl;
	}
	return 0;
}

