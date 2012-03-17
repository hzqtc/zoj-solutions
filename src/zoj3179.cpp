#include <iostream>
#include <string>

using namespace std;

const int LineLength = 6;

int sum(int a, int b)
{
	return (a + b) * (b - a + 1) / 2;
}

int main()
{
	int cse;
	cin >> cse;
	while(cse--)
	{
		int x, y, n = 0;
		string line;
		cin >> x >> y;
		
		for(int i = 0; i < 2; i++)
		{
			cin >> line;
			for(int k = 0, weight = 500000; k < LineLength; k++)
			{
				if(line[k] == '|')
					n += weight * (1 - i);
				weight /= 10;
			}
		}

		cin >> line;

		for(int i = 0; i < 5; i++)
		{
			cin >> line;
			for(int k = 0, weight = 100000; k < LineLength; k++)
			{
				if(line[k] == '|')
					n += weight * i;
				weight /= 10;
			}
		}

		if(sum(x, y) == n)
			cout << "No mistake" << endl;
		else
			cout << "Mistake" << endl;
	}
}
