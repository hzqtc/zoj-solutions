#include <iostream>

using namespace std;

int main()
{
	int casecount,i;
	int stripcount,j;
	int outlet,s;
	
	cin>>casecount;
	for(i=0;i<casecount;i++)
	{
		cin>>stripcount;
		outlet = 1;
		for(j=0;j<stripcount;j++)
		{
			cin>>s;
			outlet += s - 1;
		}
		cout<<outlet<<endl;
	}
	
	return 0;
}
