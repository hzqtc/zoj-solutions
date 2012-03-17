#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int maxlength = 7;

int main()
{
	void convert(string& digit,const int& b1,const int& b2);

	string digit;
	int basefrom,baseto;

	while(cin>>digit)
	{
		cin>>basefrom>>baseto;
		convert(digit,basefrom,baseto);
		if(digit.size() <= maxlength)
			cout<<setw(maxlength)<<setiosflags(ios::right)<<digit;
		else
			cout<<setw(maxlength)<<setiosflags(ios::right)<<"ERROR";
		cout<<endl;
	}

	return 0;
}

void convert(string& digit,const int& b1,const int& b2)
{
	int power(int base,int n);
	inline int todigit(const char& c);
	inline char tochar(const int& num);

	int len = digit.size(),i,j;
	int newnum[100],dec = 0;

	for(i=0;i<len;i++)
	{
		dec += todigit(digit[i]) * power(b1,len - i - 1);
	}
	i = 0;
	while(dec)
	{
		newnum[i++] = dec % b2;
		dec /= b2;	
	}
	digit = "";
	for(j=i-1;j>=0;j--)
	{
		digit += tochar(newnum[j]);
	}
}

int power(int base,int n)
{
	int p = 1;

	for(int i = 1;i<=n;i++)
	{
		p *= base;
	}

	return p;
}

int todigit(const char& c)
{
	if(c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	else if(c >= '0' && c <= '9')
		return c - '0';
}

char tochar(const int& num)
{
	if(num >= 10 && num <= 16)
		return num - 10 + 'A';
	else if(num >=0 && num <= 9)
		return num + '0';
}
