#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(const vector<int>& v)
{
	int min = 2008;
	for(vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
	{
		if(*iter < min)
			min = *iter;
	}
	return min;
}

int max(const vector<int>& v)
{
	int max = 0;
	for(vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
	{
		if(*iter > max)
			max = *iter;
	}
	return max;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n;
		cin >> n;
		vector<int> m;
		while(n--)
		{
			int i;
			cin >> i;
			m.push_back(i);
		}
		if(s == "Faster")
			cout << min(m) << endl;
		else
			cout << max(m) << endl;
	}
	return 0;
}
