#include <iostream>

using namespace std;

int main()
{
	int numcount,i,j;
	const int MAX = 5000;
	int num[MAX];
	int save;
	int min,inver;
	int start;

	while(cin>>numcount)
	{
		for(i=0;i<numcount;i++)
		{
			cin>>num[i];
		}
		min = 0;
		for(i=0;i<numcount;i++)
		{
			for(j=i+1;j<numcount;j++)
			{
				if(num[j] < num[i])
					min++;
			}
			if(i == 0)
				save = min;
		}

		inver = min;
		for(start=1;start<numcount;start++)
		{
			inver -= save;
			for(i=start;i<numcount;i++)
			{
				if(num[i] > num[start - 1])
					inver++;
			}
			for(i=0;i<start-1;i++)
			{
				if(num[i] > num[start - 1])
					inver++;
			}
			save = 0;
			for(i=start+1;i<numcount;i++)
			{
				if(num[i] < num[start])
					save++;
			}
			for(i=0;i<start;i++)
			{
				if(num[i] < num[start])
					save++;
			}
			if(min > inver)
				min = inver;
		}

		cout<<min<<endl;
	}

	return 0;
}
