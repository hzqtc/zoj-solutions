#include <stdio.h>
#include <string.h>

#define MAX	1000

int main()
{
	int casecount,i;
	int base;
	char number[MAX];
	int index,digitsum;
	
	int convert2int(char * num,int base);
	int power(int b,int n);
	
	scanf("%d",&casecount);
	
	for(i=0;i<casecount;i++)
	{
		if(i > 0)
			putchar('\n');
			
		while(scanf("%d",&base) ,base != 0)
		{
			index = digitsum = 0;
			scanf("%s",number);
			while(number[index] != '\0')
			{
				digitsum += number[index] - '0';
				index++;
			}
			if(convert2int(number,base) % digitsum == 0)
				puts("yes");
			else
				puts("no");
		}
	}

	return 0;
}

int convert2int(char * num,int base)
{
	int re = 0;
	int i;
	
	for(i=strlen(num)-1;i>=0;i--)
	{
		re += (num[i] - '0') * power(base,strlen(num) - 1 - i);
	}
	
	return re;
}

int power(int b,int n)
{
	int i,re = 1;
	
	for(i=0;i<n;i++)
	{
		re *= b;
	}
	
	return re;
}
