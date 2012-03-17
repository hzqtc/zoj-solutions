#include <iostream>

using namespace std;


int main()
{
	const int MAX = 100;
	int red[MAX][MAX];
	int green[MAX][MAX];
	int blue[MAX][MAX];
	int r,c;
	int gray;
	int caseindex = 1;
	
	while(cin >> r >> c , !(r == 0 && c == 0))
	{
		int i,j;
		
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin >> red[i][j];
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin >> green[i][j];
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin >> blue[i][j];
			}
		}
		
		int color;
		
		cout <<"Case " << caseindex++ << ":\n";
		for(i=0;i<r;i++)
		{
			color = red[i][0] + green[i][0] + blue[i][0];
			cout << color / 3;
			for(j=1;j<c;j++)
			{
				color = red[i][j] + green[i][j] + blue[i][j];
				cout << ',' << color / 3;
			}
			cout << endl;
		}
	}
	
	return 0;
}

