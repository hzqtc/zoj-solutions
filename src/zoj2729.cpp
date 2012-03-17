#include <cstdio>

using namespace std;

int main()
{
	int index16,index7;
	int num16,num7;
	const int mask = 1;
	int sum;
	int count;
	int sign;
	
	while(scanf("%d",&count) , count != -1)
	{
		index7 = 6;
		num7 = 0;
		sum = 0;
		while(count--)
		{
			scanf("%d",&num16);
			index16 = 15;
			while(index16 >= 0)
			{
				if(index7 == 6)
					sign = (num16 & (mask << index16)) >> index16;
				else
					num7 |= ((num16 & (mask << index16)) >> index16) << index7;
				
				if(index7 == 0)
				{
					if(sign == 0)
						sum += num7;
					else
						sum -= num7;
					index7 = 7;
					num7 = 0;
				}
				index16--;
				index7--;
			}
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
