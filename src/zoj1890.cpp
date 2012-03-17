#include <cstdio>
#include <cstring>

using namespace std;

class time
{
private:
	int hour,min,sec;

public:
	time();
	void read(char s[]);
	int tosec();
	friend time& operator-(time& a,const time& b);
};

int main()
{
	time begin,end;
	double distant = 0;
	double speed;
	int mh,mm,ms;
	const int LEN = 100;
	char s[LEN];
	char c;
	int i;

	speed = 0.0;
	while(scanf("%s",s) != EOF)
	{
		end.read(s);
		distant += speed * ((end - begin).tosec() / 3600.0);

		if((c = getchar()) != '\n')
			scanf("%lf",&speed);
		else
			printf("%s %.2lf km\n",s,distant);

		begin.read(s);
	}

	return 0;
}

time::time()
{
	this->hour = this->min = this->sec = 0;
}

void time::read(char s[])
{
	int i = 0;

	this->hour  = s[i++] - '0';
	this->hour *= 10;
	this->hour += s[i++] - '0';
	i++;
	this->min   = s[i++] - '0';
	this->min  *= 10;
	this->min  += s[i++] - '0';
	i++;
	this->sec   = s[i++] - '0';
	this->sec  *= 10;
	this->sec  += s[i++] - '0';
}

int time::tosec()
{
	return this->hour * 3600 + this->min * 60 + this->sec;
}

time& operator-(time& a,const time& b)
{
	a.sec -= b.sec;
	if(a.sec < 0)
	{
		a.sec += 60;
		a.min--;
	}
	a.min -= b.min;
	if(a.min < 0)
	{
		a.min += 60;
		a.hour--;
	}
	a.hour -= b.hour;

	return a;
}

