#include <iostream>

using namespace std;

int main()
{
	long long x,y;
	long long minx,miny,maxx,maxy;

	while(1)
	{
		cin>>x>>y;
		if(x == 0 && y == 0)
			break;
		minx = maxx = x;
		miny = maxy = y;
		while(cin>>x>>y , !(x == 0 && y == 0))
		{
			if(x<minx)
				minx = x;
			else if(x > maxx)
				maxx = x;

			if(y < miny)
				miny = y;
			else if(y > maxy)
				maxy = y;
		}
		cout<<minx<<' '<<miny<<' '<<maxx<<' '<<maxy<<endl;
	}

	return 0;
}
