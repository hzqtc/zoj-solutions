#include <iostream>
#include <string>

using namespace std;

int main()
{
	int caseCount;
	cin >> caseCount;
	while(caseCount--)
	{
		int len;
		string a, b;
		string word;
		cin >> len;
		while(len--)
		{
			cin >> word;
			a += word[0];
		}
		cin >> len;
		while(len--)
		{
			cin >> word;
			b += word[0];
		}
		if(a == b)
			cout << "SAME" << endl;
		else
			cout << "DIFFERENT" << endl;
	}
	return 0;
}
