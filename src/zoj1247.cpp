#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
	string line;
	struct
	{
		int x;
		int y;
		int x_sqrt2;
		int y_sqrt2;
	}step;
	string dir;
	int n;
	const double sqr = sqrt(2.0);
	int caseindex = 0;

	while(cin >> line , line != "END")
	{
		caseindex++;
		for(int i = 0;i<line.length();i++)
		{
			if(line[i] == ',')
				line[i] = ' ';
			else if(line[i] == '.')
				line.erase(i,i);
		}
		istringstream instr(line);
		step.x = step.y = step.x_sqrt2 = step.y_sqrt2 = 0;
		while(instr >> n >> dir)
		{
			//cout << n << ' ' << dir << endl;
			if(dir == "E")
				step.x += n;
			else if(dir == "W")
				step.x -= n;
			else if(dir == "N")
				step.y += n;
			else if(dir == "S")
				step.y -= n;
			else if(dir == "NE")
			{
				step.x_sqrt2 += n;
				step.y_sqrt2 += n;
			}
			else if(dir == "NW")
			{
				step.x_sqrt2 -= n;
				step.y_sqrt2 += n;
			}
			else if(dir == "SW")
			{
				step.x_sqrt2 -= n;
				step.y_sqrt2 -= n;
			}
			else if(dir == "SE")
			{
				step.x_sqrt2 += n;
				step.y_sqrt2 -= n;
			}
		}
		double x = step.x + (double)step.x_sqrt2 / sqr;
		double y = step.y + (double)step.y_sqrt2 / sqr;
		cout << "Map #" << caseindex << endl;
		cout << setprecision(3) << setiosflags(ios::fixed);
		cout << "The treasure is located at (" << x << ',' << y << ")." << endl;
		cout << "The distance to the treasure is " << sqrt(x * x + y * y) << "." << endl << endl;
	}
}
