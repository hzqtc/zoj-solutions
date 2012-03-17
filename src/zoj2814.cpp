#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	int distan;
	string s;
	string pair;
	bool unique;
	map<string,int> m;
	
	while(cin >> s , s != "*")
	{
		unique = true;
		for(distan=0;distan<s.length()-1;distan++)
		{
			m.clear();
			for(int i = 0;i<s.length()-distan-1;i++)
			{
				pair  = s[i];
				pair += s[i + distan + 1];
				if(++m[pair] > 1)
				{
					unique = false;
					break;
				}
			}
			if(unique == false)
				break;
		}
		cout << s << " is" << (unique == false ? " NOT" : "") << " surprising." << endl;
	}
	
	return 0;
}

