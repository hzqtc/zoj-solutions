#include <iostream>

using namespace std;

int main()
{
	int day;
	int casecount,i;
	int coin;

	cin>>casecount;
	for(i=0;i<casecount;i++)
	{
		if(i > 0)
			cout<<endl;
		while(cin>>day , day != 0)
		{
			int add = 1,index = 1;
			int loop;
			coin = 0;
			loop = 0;
			while(index <= day)
			{
				coin += add;
				loop++;
				if(loop == add)
				{
					loop = 0;
					add++;
				}
				index++;
			}
			cout<<day<<' '<<coin<<endl;
		}
	}

	return 0;
}