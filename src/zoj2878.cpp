#include <iostream>

using namespace std;

int main()
{
	int caseCount;
	cin >> caseCount;
	while(caseCount--)
	{
		int cnt;
		cin >> cnt;
		int min = 99, max = 0;
		while(cnt--)
		{
			int i;
			cin >> i;
			if(i < min)
				min = i;
			if(i > max)
				max = i;
		}
		cout << (max - min) * 2 << endl;
	}

	return 0;
}