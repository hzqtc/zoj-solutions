#include <stdio.h>
#include <string.h>

#define LEN 16
#define COUNTMAX 14

void changebase(unsigned int num,int basis,char * newnum);
int palindrom(char * num);

int main()
{
	unsigned int num;
	char newnum[LEN];/*记录各种进位制下的数字（字符串，最长是50000的二进制数——16位！）*/
	int basis[COUNTMAX],basecount;/*最多只有14个basis*/
	int i;

	while(scanf("%ud",&num),num != 0)
	{
		basecount = 0;

		for(i=2;i<=16;i++)
		{
			changebase(num,i,newnum);
			if(palindrom(newnum) == 0) 
			{
				basis[basecount++] = i;
			}
		}
		
		if(basecount == 0)
		{
			printf("Number %d is not a palindrom\n",num);
		}
		else
		{
			printf("Number %d is palindrom in basis ",num);
			for(i=0;i<basecount;i++)
			{
				if(i == basecount - 1)
					printf("%d",basis[i]);
				else
					printf("%d ",basis[i]);
			}
			putchar('\n');
		}
	}
}

void changebase(unsigned int num,int basis,char * newnum)
{
	int i=0;

	while(num)
	{
		newnum[i++] = num % basis + '0';
		num /= basis;
	}
	newnum[i] = '\0';
}

int palindrom(char * num)
{
	int i=0;
	int len = strlen(num);

	for(;i < len / 2;i++)
	{
		if(num[i] != num[len - i - 1])
		{
			return -1;
		}
	}

	return 0;
}