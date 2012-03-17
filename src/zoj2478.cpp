#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string tostr(int i);

int main()
{
	int casecount;
	string test;

	cin >> casecount;

	while(casecount--)
	{
		cin >> test;
		char c = test[0];
		int len = 1;
		int i = 1;
		while(i < test.length())
		{
			if(test[i] == c)
			{
				len++;
				i++;
			}
			else
			{
				if(len > 1)
				{
					test.erase(i - len + 1,len - 1);
					test.insert(i - len,tostr(len));
					i = i - len + 1 + tostr(len).length();
				}
				c = test[i];
				i++;
				len = 1;
			}
		}
		if(len > 1)
		{
			test.erase(i - len + 1,len - 1);
			test.insert(i - len,tostr(len));
			i = i - len + 1 + tostr(len).length();
		}
		cout << test << endl;
	}

	return 0;
}

string tostr(int i)
{
	ostringstream os;
	os << i;
	return os.str();
}

