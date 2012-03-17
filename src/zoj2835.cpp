#include <iostream>

using namespace std;

int main()
{
	int n;
	const int MAX = 16;
	int num[MAX][MAX];
	int cmp[1024];
	int sum,sumcopy;
	int row,col;
	int i;
	int pick;
	bool fail;

	while(cin>>n , n != 0)
	{
		for(i=0;i<1024;i++)
		{
			cmp[i] = 0;
		}
		fail = false;
		pick = 0;
		for(row=0;row<n;row++)
		{
			for(col=0;col<n;col++)
			{
				cin>>num[row][col];
				if(cmp[num[row][col] - 1] == 0)
				{
					pick++;
					cmp[num[row][col] - 1] = 1;
				}
			}
		}
		if(pick < n* n)
		{
			fail = true;
			cout<<"No"<<endl;
			continue;
		}

		for(row=0;row<n;row++)
		{
			sum = 0;
			for(col=0;col<n;col++)
			{
				sum += num[row][col];
			}
			if(row == 0)
				sumcopy = sum;
			else
			{
				if(sum != sumcopy)
				{
					fail = true;
					cout<<"No"<<endl;
					break;
				}
			}
		}
		if(fail == true)
			continue;

		for(col=0;col<n;col++)
		{
			sum = 0;
			for(row=0;row<n;row++)
			{
				sum += num[row][col];
			}
			if(sum != sumcopy)
			{
				fail = true;
				cout<<"No"<<endl;
				break;
			}
		}
		if(fail == true)
			continue;

		sum = 0;
		for(i=0;i<n;i++)
		{
			sum += num[i][i];
		}
		if(sum != sumcopy)
		{
			fail = true;
			cout<<"No"<<endl;
			continue;
		}

		sum = 0;
		for(i=0;i<n;i++)
		{
			sum += num[i][n - 1 - i];
		}
		if(sum != sumcopy)
		{
			fail = true;
			cout<<"No"<<endl;
			continue;
		}
		if(fail == false)
			cout<<"Yes"<<endl;
	}

	return 0;
}
