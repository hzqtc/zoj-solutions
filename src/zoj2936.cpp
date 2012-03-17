#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Entry
{
public:
	char name;

	Entry(char n): name(n) {}
	Entry(): name('\0') {}

	string GetRights()
	{
		vector<char> v;
		for(map<char, bool>::iterator iter = rights.begin(); iter != rights.end(); iter++)
		{
			if(iter->second == true)
				v.push_back(iter->first);
		}
		sort(v.begin(), v.end());
		return string(v.begin(), v.end());
	}

	void AddRight(char r)
	{
		rights[r] = true;
	}

	void RemoveRight(char r)
	{
		rights[r] = false;
	}

	void ClearRights()
	{
		rights.clear();
	}
private:
	map<char, bool> rights;
};

int main()
{
	string line;
	int caseCount = 1;
	while(getline(cin, line), line != "#")
	{
		map<char, Entry> docs;
		vector<char> E;
		vector<char> R;
		char c;
		enum ope
		{
			none, add, rm, eql
		}o;
		line += ',';
		istringstream sin(line);
		while(sin >> c)
		{
			switch(c)
			{
				case ',':
					for(vector<char>::iterator i1 = E.begin(); i1 != E.end(); i1++)
					{
						if(o == eql)
							docs[*i1].ClearRights();
						for(vector<char>::iterator i2 = R.begin(); i2 != R.end(); i2++)
						{
							if(o == rm)
								docs[*i1].RemoveRight(*i2);
							else if(o == add || o == eql)
								docs[*i1].AddRight(*i2);
						}
					}
					o = none;
					E.clear();
					R.clear();
					break;
				case '-':
					o = rm;
					break;
				case '+':
					o = add;
					break;
				case '=':
					o = eql;
					break;
				default:
					if(o == none)
					{
						E.push_back(c);
						docs.insert(make_pair(c, Entry(c)));
					}
					else
						R.push_back(c);
					break;
			}
		}
		cout << caseCount++ << ':';
		string r = "", pr = "";
		string owner = "";
		for(map<char, Entry>::iterator iter = docs.begin(); iter != docs.end(); iter++)
		{
			if((r = iter->second.GetRights()) != "")
			{
				if(r == pr)
					owner += iter->second.name;
				else
				{
					if(owner != "")
						cout << owner << pr;
					owner = iter->second.name;
					pr = r;
				}
			}
		}
		cout << owner << pr << endl;
	}

	return 0;
}
