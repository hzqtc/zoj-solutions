#include <iostream>
#include <string>
#include <map>

using namespace std;

void process(string& s1,string& s2,string& s12,int len);

int main()
{
	string s1,s2,des;
	string s12;
	map<string,int> alls;
	int casecount,caseindex;
	int length;
	
	cin >> casecount;
	for(caseindex=1;caseindex<=casecount;caseindex++)
	{
		cin >> length;
		cin >> s1 >> s2 >> des;
		alls.clear();
		int procount = 0;
		while(1)
		{
			process(s1,s2,s12,length);
			procount++;
			if(s12 == des)
			{
				cout << caseindex << ' ' << procount << endl;
				break;
			}
			else
			{
				if(++alls[s12] > 1)
				{
					cout << caseindex << " -1" << endl;
					break;
				}
			}
		}
	}
}

void process(string& s1,string& s2,string& s12,int len)
{
	s12 = "";
	for(int i = 0;i<len;i++)
	{
		s12 += s2[i];
		s12 += s1[i];
	}
	
	s1 = s12.substr(0,len);
	s2 = s12.substr(len,len);
}

