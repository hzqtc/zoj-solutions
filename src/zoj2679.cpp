#include <iostream>

using namespace std;

int main()
{
	int d1,d2,d3,d4,d5;
	int total,n;
	int casecount;
	bool none;

	cin >> casecount;
	while(casecount--)
	{
		cin >> n >> d2 >> d3 >> d4;
		none = true;
		for(d1=9;d1>0;d1--)
		{
			for(d5=9;d5>=0;d5--)
			{
				total = d1 * 10000 + d2 * 1000 + d3 * 100 + d4 * 10 + d5;
				if(total % n == 0)
				{
					none = false;
					break;
				}
			}
			if(none == false)
				break;
		}
		if(none == true)
			cout << 0 << endl;
		else
			cout << d1 << ' ' << d5 << ' ' << total / n << endl;
	}

	return 0;
}
