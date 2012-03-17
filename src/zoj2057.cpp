#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Path
{
	Path(const vector<string>& v)
	{
		dirs = v;
	}
	vector<string> dirs;
};

vector<string> Split(const string s, char t)
{
	vector<string> re;
	int len = s.length();
	int start = 0, end = 1;
	while(end < len)
	{
		if(s[end] == t)
		{
			re.push_back(s.substr(start, end - start));
			start = ++end;
		}
		end++;
	}
	re.push_back(s.substr(start, end - start));

	return re;
}

bool cmp(const Path& a, const Path& b)
{
	unsigned int i = 0;
	while(1)
	{
		if(i >= a.dirs.size())
			return true;
		else if(i >= b.dirs.size())
			return false;
		if(a.dirs[i] != b.dirs[i])
			return a.dirs[i] < b.dirs[i];
		i++;
	}
}

void Print(const Path& p)
{
	for(unsigned int i = 0; i < p.dirs.size(); i++)
		cout << string(i, ' ') << p.dirs[i] << endl;
}

void Print(const Path& p, const Path& pre)
{
	bool output = false;
	for(unsigned int i = 0; i < p.dirs.size(); i++)
	{
		if(output == false && i < pre.dirs.size() && p.dirs[i] == pre.dirs[i])
			continue;
		output = true;
		cout << string(i, ' ') << p.dirs[i] << endl;
	}
}

int main()
{
	int caseCount;
	cin >> caseCount;
	while(caseCount--)
	{
		int n;
		cin >> n;
		vector<Path> paths;
		while(n--)
		{
			string line;
			cin >> line;
			paths.push_back(Path(Split(line, '\\')));
		}
		sort(paths.begin(), paths.end(), cmp);
		for(unsigned int i = 0; i < paths.size(); i++)
		{
			if(i > 0)
				Print(paths[i], paths[i - 1]);
			else
				Print(paths[i]);
		}
		if(caseCount > 0)
			cout << endl;
	}

	return 0;
}
