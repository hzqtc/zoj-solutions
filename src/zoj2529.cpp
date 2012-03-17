#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int prime[] =
{
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113
};

class hnum
{
public:
	hnum();
	hnum(string& s);
	friend hnum operator+(const hnum& a,const hnum& b);
	friend ostream& operator<<(ostream& os,const hnum& h);
private:
	static const int MAX = 30;
	int digits[MAX];
	int len;
};

int main()
{
	string a,b;

	while(cin >> a >> b)
	{
		hnum num1(a),num2(b);
		cout << (num1 + num2) << endl;
	}

	return 0;
}

hnum::hnum()
{
	for(int i = 0;i<MAX;i++)
		this->digits[i] = 0;
	this->len = 0;
}

hnum::hnum(string& s)
{
	int i;
	for(i = 0;i<MAX;i++)
		this->digits[i] = 0;
	this->len = 0;
	
	for(i=0;i<s.length();i++)
	{
		if(s[i] == ',')
			s[i] = ' ';
	}
	
	istringstream iss(s);
	int temp;
	
	while(iss >> temp)
		this->digits[this->len++] = temp;
		
	for(int i=0;i<this->len/2;i++)//内部存储，使用倒序表示，以方便就加法进位
	{
		int swap = this->digits[i];
		this->digits[i] = this->digits[len - 1 - i];
		this->digits[len - 1 - i] = swap;
	}
}

hnum operator+(const hnum& a,const hnum& b)
{
	hnum re;
	int i = 0;
	
	while(i < a.len || i < b.len)
	{
		re.digits[i] += a.digits[i] + b.digits[i];
		re.len = i + 1;
		if(re.digits[i] >= prime[i])
		{
			re.digits[i] -= prime[i];
			re.digits[i + 1]++;
			re.len++;
		}
		i++;
	}

	return re;
}

ostream& operator<<(ostream& os,const hnum& h)
{
	os << h.digits[h.len - 1];
	for(int i = h.len - 2;i>=0;i--)
		cout << ',' << h.digits[i];
		
	return os;
}

