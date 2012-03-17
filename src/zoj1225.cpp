#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

enum DataType
{
	TypeStr, TypeInt
};

int ParseInt(const string& s)
{
	int i;
	int l = s.length();
	int re = 0;
	if(s[0] == '-')
		i = 1;
	else
		i = 0;
	for(; i < l; i++)
		re = re * 10 + s[i] - '0';
	if(s[0] == '-')
		re = -re;
	return re;
}

bool StrCmp(const string& a, const string& b)	// compare two strings after convertted to lower case
{
	for(int i = 0;; i++)
	{
		char c1 = a[i], c2 = b[i];
		if(c1 >= 'A' && c1 <= 'Z')
			c1 += 'a' - 'A';
		if(c2 >= 'A' && c2 <= 'Z')
			c2 += 'a' - 'A';
		if(c1 != c2)
			return c1 < c2;
	}
}

int main()
{
	string line;
	string tmp;
	while(getline(cin, line))
	{
		vector<string> str;
		vector<int> integer;
		vector<DataType> list;
		if(line == ".")
			break;
		istringstream s(line);
		while(s >> tmp)
		{
			tmp = tmp.substr(0, tmp.length() - 1);		// the last char is ',' or '.', delete it from the string
			if((tmp[0] >= '0' && tmp[0] <= '9') || tmp[0] == '-')
			{
				integer.push_back(ParseInt(tmp));
				list.push_back(TypeInt);
			}
			else
			{
				str.push_back(tmp);
				list.push_back(TypeStr);
			}
		}
		sort(str.begin(), str.end(), StrCmp);
		sort(integer.begin(), integer.end());
		int i = 0, j = 0;
		for(vector<DataType>::iterator iter = list.begin(); iter != list.end(); iter++)
		{
			if(iter != list.begin())
				cout << ", ";
			if(*iter == TypeInt)
				cout << integer[i++];
			else if(*iter == TypeStr)
				cout << str[j++];
		}
		cout << '.' << endl;
	}
	return 0;
}

