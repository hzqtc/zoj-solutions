#include <iostream>

using namespace std;

class equation
{
public:
	equation();
	void calc(string& s);
private:
	int x;
	int num;
};

int main()
{
	int casecount;
	string equ;

	cin >> casecount;
	while(casecount--)
	{
		cin >> equ;
		equation a;
		a.calc(equ);
	}

	return 0;
}

equation::equation()
{
	x = num = 0;
}

void equation::calc(string& s)
{
	s += '#';
	int i = 0;
	enum {left = 1,right = -1} pos = left;//left side of the equation
	enum {po = 1,ne = -1} sign = po;//positive or negative
	int n = 0;//number before 'x' or just a number

	while(i < s.length())
	{
		char c = s[i];
		if(c == 'x')
		{
			if(n == 0)
				n = 1;
			this->x += pos * sign * n;
			n = 0;
		}
		else if(c >= '0' && c <= '9')
			n = n * 10 + c - '0';
		else if(c == '=')
		{
			this->num += -1 * pos * sign * n;
			n = 0;
			pos = right;
			sign = po;
		}
		else if(c == '-')
		{
			this->num += -1 * pos * sign * n;
			n = 0;
			sign = ne;
		}
		else if(c == '+')
		{
			this->num += -1 * pos * sign * n;
			n = 0;
			sign = po;
		}
		else if(c == '#')
			this->num += -1 * pos * sign * n;

		i++;
	}

	if(this->x == 0)
	{
		if(this->num != 0)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << "IDENTITY" << endl;
	}
	else
	{
		double re = (double)num / (double)x;
		if(re >= 0)
			cout << (int)re << endl;
		else if(re < 0 && num % x)
			cout << (int)re - 1 << endl;
	}
}

