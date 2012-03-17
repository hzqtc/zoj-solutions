#include <cstdio>

using namespace std;

const int MAX = 1010;
class fib
{
	private:
		int digit[MAX];
	public:
		void init();
		fib& plus(const fib& p);
		void print();
};

int main()
{
	fib f[2];
	int num,i;

	while(scanf("%d",&num) != EOF)
	{
		f[0].init();
		f[1].init();
		for(i=3;i<=num;i++)
		{
			if(i % 2)
				f[1].plus(f[0]);
			else
				f[0].plus(f[1]);
		}
		f[num % 2].print();
	}
}

void fib::init()
{
	this->digit[0] = 1;
	for(int i = 1;i<MAX;i++)
	{
		this->digit[i] = 0;
	}
}

void fib::print()
{
	bool flag = false;

	for(int i = MAX - 1;i>=0;i--)
	{
		if(this->digit[i] != 0)
			flag = true;
		if(flag == true)
			printf("%d",this->digit[i]);
	}
	putchar('\n');
}

fib& fib::plus(const fib& p)
{
	for(int i=0;i<MAX;i++)
	{
		this->digit[i] += p.digit[i];
		while(this->digit[i] > 9)
		{
			this->digit[i] -= 10;
			this->digit[i + 1]++;
		}
	}

	return *this;
}
