#include <cstdio>
#include <string>
#include <map>

using namespace std;

string num[16];
map<string, int> value;
char tmp[100000];

void GenNum();

int main()
{
	GenNum();
	int c;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%s", tmp);
		string a(tmp);
		scanf("%s", tmp);
		string b(tmp);
		int ia = value[a];
		int ib = value[b];
		printf("%s\n", num[ia + ib].c_str());
	}
	return 0;
}

void GenNum()
{
	num[0] = "{}";
	num[1] = "{{}}";
	value["{}"] = 0;
	value["{{}}"] = 1;
	for(int i = 2; i <= 15; i++)
	{
		string s = "{";
		for(int j = 0; j < i; j++)
		{
			if(j > 0)
				s += ",";
			s += num[j];
		}
		s += "}";
		num[i] = s;
		value[s] = i;
	}
}
