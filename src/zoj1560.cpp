#include <iostream>
#include <iomanip>
#include <cmath>

#define PI		3.14159265358979323846
#define RAD(x)	((double)((x) / 180.0 * PI))

using namespace std;

int main()
{
    int casecount;
    int cx1,cy1,cd1;
    int cx2,cy2,cd2;
    double ox,oy;
    
    cin >> casecount;
    while(casecount--)
    {
        cin >> cx1 >> cy1 >> cd1 >> cx2 >> cy2 >> cd2;
        if(cd1 == 180 || cd1 == 0)//l1 : x = cx1; l2 : y - cy2 = k2 * (x - cx2)
        {
        	ox = (double)cx1;
        	oy = cy2 + (-tan(RAD(cd2 - 90))) * (double)(cx1 - cx2);
    	}
    	else if(cd2 == 180 || cd2 == 0)
    	{
    		ox = cx2;
    		oy = cy1 + (-tan(RAD(cd1 - 90))) * (double)(cx2 - cx1);
    	}
    	else
    	{
    		double k1 = -tan(RAD(cd1 - 90)),k2 = -tan(RAD(cd2 - 90));
          	ox = (cy2 - cy1 - k2 * cx2 + k1 * cx1) / (k1 - k2);
          	oy = cy1 + k1 * (ox - cx1);
    	}

		cout << setprecision(4) << setiosflags(ios::fixed);
		//if((int)(ox * 100000) % 10 >= 5)
		//	ox += 0.0001;
		//if((int)(oy * 100000) % 10 >= 5)
		//	oy += 0.0001;
    	cout << ox << ' ' << oy << endl;
	}
	
	return 0;
}
