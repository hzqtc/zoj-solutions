#include <cstdio>

using namespace std;

const int I_COUNT = 8;
const int F_COUNT = 2;

class dollar
{
public:
	dollar();
	void init();
	void read();
	void print();
	friend dollar operator+(const dollar& a,const dollar& b);
private:
	int int_part[8];
	int float_part[2];
	int i_len;
};

int main()
{
	int dollarcount;
	dollar count,add;
	
	while(scanf("%d",&dollarcount) , dollarcount != 0)
	{
		count.init();
		while(dollarcount--)
		{
			add.read();
			count = count + add;
		}
		count.print();
	}
	
	return 0;
}

dollar::dollar()
{
	this->init();
}

void dollar::init()
{
	int i;
	
	for(i=0;i<I_COUNT;i++)
		this->int_part[i] = 0;
	for(i=0;i<F_COUNT;i++)
		this->float_part[i] = 0;
	this->i_len = 0;
}

void dollar::read()
{
	char c;
	bool i_or_f = true;
	int i = 0;
	
	this->init();
	while((c = getchar()) != '$')
		;
	
	while((c = getchar()) != '\n')
	{
		if(c == '.')
		{
			i_or_f = false;
			this->i_len = i;
			i = -1;
		}
		else if(c == ',')
			continue;
		else
		{
			if(i_or_f == true)
				this->int_part[i] = c - '0';
			else
				this->float_part[F_COUNT - 1 - i] = c - '0';
		}		
		i++;
	}
	
	int swap;
	for(i=0;i<this->i_len/2;i++)
	{
		swap = this->int_part[i];
		this->int_part[i] = this->int_part[this->i_len - 1 - i];
		this->int_part[this->i_len - 1 - i] = swap;
	}
}

void dollar::print()
{
	int i;
	int putcount = 0;
		
	putchar('$');
	for(i = this->i_len - 1;i>=0;i--)
	{
		if((this->i_len - putcount) % 3 == 0 && putcount != 0)
			putchar(',');
		putchar(this->int_part[i] + '0');
		putcount++;
	}
	if(this->i_len == 0)
		putchar('0');
	putchar('.');
	for(i = F_COUNT - 1;i>=0;i--)
		putchar(this->float_part[i] + '0');
	putchar('\n');
}

dollar operator+(const dollar& a,const dollar& b)
{
	dollar sum;
	int i;

	for(i=0;i<F_COUNT;i++)
	{
		sum.float_part[i] += a.float_part[i] + b.float_part[i];
		if(sum.float_part[i] > 9)
		{
			sum.float_part[i] -= 10;
			if(i == F_COUNT - 1)
				sum.int_part[0]++;
			else
				sum.float_part[i + 1]++;
		}
	}

	for(i=0;i<I_COUNT;i++)
	{
		sum.int_part[i] += a.int_part[i] + b.int_part[i];
		if(sum.int_part[i] > 9)
		{
			sum.int_part[i] -= 10;
			sum.int_part[i + 1]++;
		}
		if(sum.int_part[i] != 0)
			sum.i_len = i + 1;
	}

	return sum;
}
