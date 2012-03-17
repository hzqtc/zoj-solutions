#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int casecount;
	int i;
	
	cin >> casecount;
	while(casecount--)
	{
		map<char, int> header;
		char text[100][26];
		string tmp;
		cin >> tmp;
		for(i = 0;i<tmp.length();i++)
			header[tmp[i]] = i;
		cin >> tmp;
		int sp = 0;

		int len[26] = {0};
		int l = tmp.length() / header.size();
		int m = tmp.length() - l * header.size();
		i = 0;
		while(i < m)
			len[i++] = l + 1;
		while(i < header.size())
			len[i++] = l;
		
		for(map<char, int>::iterator iter = header.begin();iter != header.end();iter++)
		{
			int col = iter->second;
			for(int j = 0;j<len[col];j++)
				text[j][col] = tmp[sp++] - 'A' + 'a';
		}

		for(i=0;i<sp;i++)
			cout.put(text[i / header.size()][i % header.size()]);
		cout << endl;
	}
	
	return 0;
}
