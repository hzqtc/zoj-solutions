#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const int MAX = 1024;
	class team
	{
	public:
		string name;
		char passwd[16];
		int modified;
	}t[MAX];
	int teamcount,i;
	int mcount;
	
	int modify(char * p);
	
	while(cin>>teamcount , teamcount != 0)
	{
		for(i=0;i<teamcount;i++)
		{
			cin>>t[i].name>>t[i].passwd;
		}
		mcount = 0;
		for(i=0;i<teamcount;i++)
		{
			if(t[i].modified = modify(t[i].passwd))
				mcount++;
		}
		if(mcount == 0)
		{
			cout<<"No account is modified."<<endl;
			continue;
		}
		cout<<mcount<<endl;
		for(i=0;i<teamcount;i++)
		{
			if(t[i].modified)
				cout<<t[i].name<<' '<<t[i].passwd<<endl;
		}
	}
	
	return 0;
}

int modify(char * p)
{
	int m = 0;
	
	for(int i = 0;i<strlen(p);i++)
	{
		m++;
		if(p[i] == '1')
			p[i] = '@';
		else if(p[i] == 'l')
			p[i] = 'L';
		else if(p[i] == '0')
			p[i] = '%';
		else if(p[i] == 'O')
			p[i] = 'o';
		else
			m--;
	}
	
	return m;
}
