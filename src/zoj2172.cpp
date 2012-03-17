#include <iostream>
#include <string>

using namespace std;

const int MAX = 16;

struct name
{
	string str;
	int index;
}s[MAX];

int main()
{
	int namecount,i;
	int caseindex = 1;
	
	while(cin>>namecount , namecount != 0)
	{
		for(i=0;i<namecount;i++)
		{
			cin>>s[i].str;
			s[i].index = i % 2 ? namecount - i / 2 : i / 2 + 1;
		}
		cout<<"SET "<<caseindex++<<endl;
		for(i=1;i<=namecount;i++)
		{
			for(int j = 0;j<namecount;j++)
			{
				if(s[j].index == i)
				{
					cout<<s[j].str<<endl;
					break;
				}
			}
		}
	}
	
	return 0;
}
