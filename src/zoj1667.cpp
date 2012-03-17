#include <iostream>
#include <string>

using namespace std;

class die
{
public:
	int n,s,w,e,t,b;

	die();
	int rotate(string d);
};

int main()
{
	string d;
	int rcount;

	while(cin>>rcount , rcount != 0)
	{
		die mydie;

		while(rcount--)
		{
			cin>>d;
			mydie.rotate(d);
		}
		cout<<mydie.t<<endl;
	}

	return 0;
}

die::die()
{
	this->n = 2;
	this->s = 5;
	this->w = 3;
	this->e = 4;
	this->t = 1;
	this->b = 6;
}

int die::rotate(string d)
{
	int swap;

	if(d == "north")
	{
		swap = t;
		t = s;
		s = b;
		b = n;
		n = swap;
	}
	else if(d == "south")
	{
		swap = t;
		t = n;
		n = b;
		b = s;
		s = swap;
	}
	else if(d == "east")
	{
		swap = t;
		t = w;
		w = b;
		b = e;
		e = swap;
	}
	else if(d == "west")
	{
		swap = t;
		t = e;
		e = b;
		b = w;
		w = swap;
	}

	return t;
}
