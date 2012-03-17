#include <iostream>

using namespace std;

const int MAX = 8;

class turingnum
{
private:
	int digit[MAX];
public:
	turingnum();
	void init();
	friend turingnum operator+(const turingnum& a,const turingnum& b);
	friend bool operator==(const turingnum& a,const turingnum& b);
	void read();
};

int main()
{
	turingnum p1,p2,sum;
	turingnum plus;
	const turingnum zero;

	while(1)
	{
		p1.read();
		p2.read();
		sum.read();
		plus = p1 + p2;
		if(plus == sum)
			cout<<"True"<<endl;
		else
			cout<<"False"<<endl;

		if(p1 == zero && p1 == zero && sum == zero)
			return 0;
	}
}

turingnum::turingnum()
{
	this->init();
}

void turingnum::init()
{
	for(int i = 0;i<MAX;i++)
	{
		this->digit[i] = 0;
	}
}

void turingnum::read()
{
	char c;
	int i = 1;

	this->init();
	while((c = getchar()) < '0' || c > '9')
		;
	this->digit[0] = c - '0';

	while((c = getchar()) >= '0' && c <= '9')
		this->digit[i++] = c - '0';
}

turingnum operator+(const turingnum& a,const turingnum& b)
{
	turingnum s;
	
	for(int i = 0;i<MAX;i++)
	{
		s.digit[i] += (a.digit[i] + b.digit[i]);
		while(s.digit[i] > 9)
		{
			s.digit[i] -= 10;
			s.digit[i + 1]++;
		}
	}

	return s;
}

bool operator==(const turingnum& a,const turingnum& b)
{
	for(int i = 0;i<MAX;i++)
	{
		if(a.digit[i] != b.digit[i])
			return false;
	}

	return true;
}
