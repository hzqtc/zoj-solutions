#include <iostream>

using namespace std;

int main()
{
	int n,m;
	const int MAX = 12;
	int squ[MAX][MAX];
	
	while(cin >> n >> m , !(n == 0 && m == 0))
	{
		int i,j;
		bool all = true;
		bool adj = false;
		
		for(i=0;i<MAX;i++)
		{
			for(j=0;j<MAX;j++)
				squ[i][j] = 1;
		}
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				cin >> squ[i][j];
		}
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(squ[i][j] == 0)
				{
					all = false;
					if(squ[i - 1][j] == 0 || squ[i + 1][j] == 0 || squ[i][j - 1] == 0 || squ[i][j + 1] == 0)
					{
						adj = true;
						break;
					}
				}
			}
			if(adj == true)
				break;
		}
		if(all == false && adj == false)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}

