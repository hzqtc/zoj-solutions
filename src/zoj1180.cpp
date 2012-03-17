#include<cstdio>
#include <cstring>

using namespace std;

inline int digitsum(int n);

int main()
{
	int num;
	int i,temp;
	char numstr[10];
	
	for(num=1;num<=1000000;num++)
	{
		sprintf(numstr,"%d",num);
		temp = num - 9 * strlen(numstr) > 0 ? num - 9 * strlen(numstr) : 1;
		for(i=num-1;i>=temp;i--)
		{
			if(i + digitsum(i) == num)
				break;
		}
		if(i < temp)
			printf("%d\n",num);
	}
	
	return 0;
}

int digitsum(int n)
{
	int s = 0;
	
	while(n)
	{
		s += n % 10;
		n /= 10;
	}
	
	return s;
}
