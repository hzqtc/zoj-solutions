#include <cstdio>

using namespace std;

int main()
{
	int count;
	int num;
	int ten,digit;

	scanf("%d\n",&count);

	while(count--)
	{
		scanf("%d",&num);
		
		for(ten=1;num > ten * 10;ten *= 10)
		{
			digit = (num / ten) % 10;
			if(digit < 5)
				num -= digit * ten;
			else
				num += (10 - digit) * ten;
		}
		printf("%d\n",num);
	}

	return 0;
}