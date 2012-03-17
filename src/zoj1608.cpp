#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x,y,r1,r2;
	double temp;

	while(cin>>x>>y>>r1>>r2)
	{
		if(y < r1 + r2)
		{
			cout<<"No"<<endl;
			continue;
		}
		if((temp = (r1 + r2) * (r1 + r2) - (y - r1 - r2) * (y - r1 - r2)) < 0)
		{
			cout<<"No"<<endl;
			continue;
		}
		if(x - sqrt(temp) - r1 - r2 >= 0.0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	return 0;
}
