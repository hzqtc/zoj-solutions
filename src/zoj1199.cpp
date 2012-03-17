#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int square(int);

int main()
{
	int casecount;
	int x1,y1,r1,x2,y2,r2;

	cin >> casecount;
	while(casecount--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if(r2 > r1)
		{
			int swap;
			swap = x1;x1 = x2;x2 = swap;
			swap = y1;y1 = y2;y2 = swap;
			swap = r1;r1 = r2;r2 = swap;
		}
		else if(r1 == r2)
		{
			cout << "Impossible." << endl;
			continue;
		}

		if(sqrt((double)(square(x1 -x2) + square(y1 - y2))) <= (double)(r1 - r2))//内含或者内切，没有公切线
		{
			cout << "Impossible." << endl;
			continue;
		}

		double x,y;

		x = (double)(r1 * x2 - r2 * x1) / (double)(r1 - r2);
		y = (double)(r1 * y2 - r2 * y1) / (double)(r1 - r2);

		cout << setprecision(2) << setiosflags(ios::fixed);
		cout << x << ' ' << y << endl;
	}

	return 0;
}

inline int square(int a)
{
	return a * a;
}