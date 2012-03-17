/*wrong answer*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN		110
#define C2I(c)		((c) >= '0' && (c) <= '9' ? (c) - '0' : (c) - 'a' + 10)
#define I2C(i)		((i) >= 0 && (i)<= 9 ? (i) + '0' : (i) - 10 + 'a')

int main()
{
	char digits[MAX_LEN];
	int sum[MAX_LEN],num[MAX_LEN];
	int index,length;
	int flag;
	
	while(scanf("%s",digits) != EOF)
	{
		length = strlen(digits);/*得到第一个数，低位到高位排列*/
		for(index=0;index<length;index++)
		{
			sum[index] = C2I(digits[length - 1 - index]);
		}
		for(;index<MAX_LEN;index++)
		{
			sum[index] = 0;
		}
		
		if(scanf("%s",digits) == EOF)
			return 0;
		
		length = strlen(digits);/*得到第二个数，低位到高位排列*/
		for(index=0;index<length;index++)
		{
			num[index] = C2I(digits[length - 1 - index]);
		}
		for(;index<MAX_LEN;index++)
		{
			num[index] = 0;
		}
		
		for(index=0;index<MAX_LEN;index++)/*加起来*/
		{
			sum[index] += num[index];
			
			while(sum[index] >= 20)
			{
				sum[index] -= 20;
				sum[index + 1]++;
			}
		}
		
		flag = 0;
		for(index = MAX_LEN - 1;index>=0;index--)/*输出*/
		{
			if(flag == 0)
			{
				if(sum[index] != 0)
					flag = 1;
			}
			
			if(flag == 1)
				putchar(I2C(sum[index]));
		}
		if(flag == 0)
				putchar('0');
		putchar('\n');
	}
	
	return 0;
}
