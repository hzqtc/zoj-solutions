#include <iostream>

using namespace std;

int main()
{
	int n1,n2,n3;
	int a,b,c;
	
	while(cin>>n1>>n2>>n3)
	{
		c = n1;
		a = (n3 + n1 - 2 * n2) / 2;
		b = (4 * n2 - 3 * n1 - n3) / 2;
		
		cout<<9 * a + 3 * b + c<<' '<<16 * a + 4 * b + c<<' '<<25 * a + 5 * b + c<<endl;
	}
	
	return 0;
}
