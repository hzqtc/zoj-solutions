#include <cstdio>

using namespace std;

class lint
{
public:
	const lint& operator++();
	const lint& operator--();
	friend lint operator+(const lint& a,const lint& b);
	void print();
	lint();
private:
	const static int MAX = 500;
	int num[MAX];
};

lint len[1000];

int main()
{
	int step;

	++len[1];
	++len[2];
	
	lint length(len[2]);
	int flag = 1;
	for(step=4;step<=1000;step++)
	{
		length = length + length;
		if(flag == 1)
			++length;
		else
			--length;
		flag = -flag;
		
		len[step - 1] = length;
	}
	
	while(scanf("%d",&step) != EOF)
	{
		len[step - 1].print();
		putchar('\n');
	}
	return 0;
}

lint::lint()
{
	for(int i = 0;i<MAX;i++)
		this->num[i] = 0;
}

const lint& lint::operator++()
{
	this->num[0]++;
	int i = 0;
	while(this->num[i] >= 10)
	{
		while(this->num[i] >= 10)
		{
			this->num[i] -= 10;
			this->num[i + 1]++;
		}
		i++;
	}
	
	return *this;
}

const lint& lint::operator--()
{
	this->num[0]--;
	int i = 0;
	while(this->num[i] < 0)
	{
		while(this->num[i] < 0)
		{
			this->num[i] += 10;
			this->num[i + 1]--;
		}
		i++;
	}
	
	return *this;

}

lint operator+(const lint& a,const lint& b)//仅适用于正数
{
	lint re;
	for(int i = 0;i<lint::MAX;i++)
	{
		re.num[i] += a.num[i] + b.num[i];
		int j = i;
		while(re.num[j] >= 10)
		{
			while(re.num[j] >= 10)
			{
				re.num[j] -= 10;
				re.num[j + 1]++;
			}
			j++;
		}
	}
	
	return re;
}

void lint::print()
{
	int i = MAX - 1;
	bool non_zero = false;
	while(i >= 0)
	{
		if(this->num[i] > 0)
			non_zero = true;
			
		if(non_zero == true)
			printf("%d",this->num[i]);
		i--;
	}
	if(non_zero == false)
		putchar('0');
}

