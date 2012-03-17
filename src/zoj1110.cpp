#include <iostream>

using namespace std;

int main()
{
	int D,C,T;
	int s,p,y,j;
	int sumdc;

	while(cin>>s>>p>>y>>j)
	{
		sumdc = (y + p + 2 * j + 26) / 3;
		D = (sumdc + 1 + s) / 2;
		C = sumdc - D;
		T = 12 + j - D - C;
		cout<<D<<' '<<C<<' '<<T<<endl;
	}

	return 0;
}
