#include <iostream>
#include <string>

using namespace std;

class MCXI
{
public:
	MCXI(int c_m,int c_c,int c_x,int c_i) : m(c_m),c(c_c),x(c_x),i(c_i)
	{
		while(i > 9)
		{
			x++;
			i -= 10;
		}
		while(x > 9)
		{
			c++;
			x -= 10;
		}
		while(c > 9)
		{
			m++;
			c -= 10;
		}
	}
	MCXI() : m(0),c(0),x(0),i(0){};

	friend MCXI operator+(const MCXI& a,const MCXI& b);
	friend istream& operator>>(istream& in,MCXI& a);
	friend ostream& operator<<(ostream& out,const MCXI& a);
private:
	int m,c,x,i;
};

int main()
{
	int casecount;
	
	cin >> casecount;
	getchar();
	while(casecount--)
	{
		MCXI a,b;
		cin >> a >> b;
		cout << a + b << endl;
	}
	
	return 0;
}

MCXI operator+(const MCXI& a,const MCXI& b)
{
	return MCXI(a.m + b.m,a.c + b.c,a.x + b.x,a.i + b.i);
}

istream& operator>>(istream& in,MCXI& a)
{
	string str;
	int value = 1;
	int i = 0;
	char c;
	
	in >> str;
	while(i < str.length())
	{
		c = str[i++];
		if(c >= '2' && c <= '9')
			value = c - '0';
		else if(c >= 'a' && c <= 'z')
		{
			switch(c)
			{
			case 'm':
				a.m = value;	break;
			case 'c':
				a.c = value;	break;
			case 'x':
				a.x = value;	break;
			case 'i':
				a.i = value;	break;
			}
			
			value = 1;
		}
		else
			break;
	}
	
	return in;
}

ostream& operator<<(ostream& out,const MCXI& a)
{
	if(a.m == 1)
		out << 'm';
	else if(a.m > 1)
		out << a.m << 'm';
		
	if(a.c == 1)
		out << 'c';
	else if(a.c > 1)
		out << a.c << 'c';
		
	if(a.x == 1)
		out << 'x';
	else if(a.x > 1)
		out << a.x << 'x';
		
	if(a.i == 1)
		out << 'i';
	else if(a.i > 1)
		out << a.i << 'i';
		
	return out;
}
