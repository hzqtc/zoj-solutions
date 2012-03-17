#include <iostream>

using namespace std;

int main()
{
	int n,m;
	double c;
	int i;
	
	while(cin>>n>>m , n != 0)
	{
		if(n - m < m)
			m = n - m;
		c = 1.0;
		for(i=1;i<=m;i++)
		{
			c *= n - m + i;
			c /= i;
		}
		cout<<(int)c<<endl;
	}

	return 0;
}
