#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int caseCount;
	cin >> caseCount;
	while(caseCount--)
	{
		int n, m;
		cin >> n >> m;
		int i;
		bool skip = false;
		stack<int> peg[3];
		for(i = n; i >= 1; i--)
			peg[0].push(i);

		int from, to;
		for(i = 1; i <= m; i++)
		{
			cin >> from >> to;
			if(skip == true)
				continue;
			from--;
			to--;
			if(peg[from].empty() == false && (peg[to].empty() || (peg[from].top() < peg[to].top())))
			{
				peg[to].push(peg[from].top());
				peg[from].pop();
				if(peg[0].empty() && peg[1].empty())
				{
					cout << i << endl;
					skip = true;
				}
			}
			else
			{
				cout << '-' << i << endl;
				skip = true;
			}
		}
		if(skip == false)
			cout << 0 << endl;
	}

	return 0;
}
