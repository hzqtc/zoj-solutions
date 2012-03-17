#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.1415926535897932;

int main()
{
	double x_max = 180 * pi / 180;
	double y_max = log(tan(pi / 4 + (85 * pi / 180) / 2));
	double x_begin,x_end,y_begin,y_end,x_mid,y_mid;
	
	double x,y;
	int level;
	string loc;
	
	while(cin >> x >> y >> level)
	{
		x = x * pi / 180;
		y = log(tan(pi / 4 + (y * pi / 180) / 2));
		
		x_begin = -x_max;
		x_end = x_max;
		x_mid = 0.0;
		y_begin = -y_max;
		y_end = y_max;
		y_mid = 0.0;
		loc = "t";
		
		for(int i = 1;i<=level;i++)
		{
			if(x >= x_mid && x <= x_end)
			{
				x_begin = x_mid;
				if(y >= y_mid && y <= y_end)
				{
					loc += "r";
					y_begin = y_mid;
				}
				else
				{
					loc += "s";
					y_end = y_mid;
				}
			}
			else
			{
				x_end = x_mid;
				if(y >= y_mid && y <= y_end)
				{
					loc += "q";
					y_begin = y_mid;
				}
				else
				{
					loc += "t";
					y_end = y_mid;
				}
			}
			x_mid = (x_begin + x_end) / 2.0;
			y_mid = (y_begin + y_end) / 2.0;
		}
		
		cout << loc << endl;
	}
	
	return 0;
}

