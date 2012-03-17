#include <iostream>

using namespace std;

inline void init(int a[]);

const int MAX = 110;

int main()
{
	int total,quorm;
	int date[MAX];
	int i;
	int datecount,j;
	int dateindex;

	while(cin>>total>>quorm , total | quorm)
	{
		init(date);
		for(i=0;i<total;i++)
		{
			cin>>datecount;
			for(j=0;j<datecount;j++)
			{
				cin>>dateindex;
				date[dateindex]++;
			}
		}
		int * max = NULL;
		for(i=0;i<MAX;i++)
		{
			if(max == NULL || *max < date[i])
				max = date + i;
		}
		if(*max < quorm)
			cout<<0<<endl;
		else
			cout<<max - date<<endl;
	}

	return 0;
}

void init(int a[])
{
	for(int i = 0;i<MAX;i++)
	{
		a[i] = 0;
	}
}