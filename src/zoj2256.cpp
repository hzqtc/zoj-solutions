#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int distance;
	double cost;
	int i;

	while(cin>>distance ,distance != 0)
	{
     	if(distance <= 4)
     		cost = 10;
		else
	    {
    		i = distance % 8;
    		cost = (distance / 8) * 18;
    		if(i <= 4)
    			cost += i * 2.4;
    		else
    			cost += (10 + (i - 4) * 2);
		}

		if(cost > (double)(int)cost)
    		cout<<setprecision(1)<<setiosflags(ios::fixed)<<cost<<endl;
		else
    		cout<<(int)cost<<endl;
	}

	return 0;
}

