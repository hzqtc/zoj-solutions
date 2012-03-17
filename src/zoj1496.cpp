#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14159;

int main()
{
	double frontcog[3],rearcog[9],diameter,target;
	int casecount,i;
	double cir;
	double get,temp;
	double * fcog,* rcog;

	cin>>casecount;

	for(i=0;i<casecount;i++)
	{
		if(i > 0)
			cout<<endl;
		cin	>>frontcog[0]>>frontcog[1]>>frontcog[2]
			>>rearcog[0]>>rearcog[1]>>rearcog[2]>>rearcog[3]>>rearcog[4]>>rearcog[5]>>rearcog[6]>>rearcog[7]>>rearcog[8]
			>>diameter>>target;

		cir = diameter * PI;
		get = 0.0;

		for(int index = 0;index < 3;index++)
		{
			for(int i = 0;i < 9;i++)
			{
				temp = frontcog[index] / rearcog[i] * cir;
				if(fabs(get  - target) > fabs(temp - target))
				{
					fcog = frontcog + index;
					rcog = rearcog + i;
					get = temp;
				}
			}
		}
		cout<<"A gear selection of "<<(int)(*fcog)<<'/'<<(int)(*rcog)<<" produces a gear size of ";
		cout<<setprecision(3);
		cout<<setiosflags(ios::fixed);
		cout<<get;
		cout<<'.'<<endl;
	}

	return 0;
}