#include <iostream>

using namespace std;

int p(int,int);

int main()
{
	int b,n,a;
	int absleft1,absleft2;
	int temp;
	
	while(cin>>b>>n , b != 0)
	{
		a = 1;
		while((temp = p(a,n)) < b)
		{
			a++;
			absleft1 = b - temp;
		}
		absleft2 = temp - b;
		if(absleft2 > absleft1)
			cout<<a - 1<<endl;
		else
			cout<<a<<endl;
	}

	return 0;
}

int p(int a,int n)
{
	int b = 1;

	for (int i = 0;i<n;i++)
	{
		b *= a;
	}
	
	return b;
}