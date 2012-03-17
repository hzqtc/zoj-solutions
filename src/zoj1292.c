#include <stdio.h>

#define	INTLEN	110

struct VeryLongInteger
{
	int digit[INTLEN];
	int length;
};

int		getlongint(struct VeryLongInteger * num);
void	addlongint(struct VeryLongInteger * sum , struct VeryLongInteger * add);
void	putlongint(struct VeryLongInteger * num);

int main()
{
	struct VeryLongInteger sum,newnum;
	int casecount,i;
	char c;
	
	scanf("%d",&casecount);
	for(i=0;i<casecount;i++)
	{
		if(i > 0)						/*there should be a blank line between output blocks*/
			putchar('\n');
			
		while((c = getchar()) == '\n')	/*jump over blank line*/
			;
		ungetc(c,stdin);				/*put the "not '\n' char" back to the stdin*/
		
		getlongint(&sum);
		while(getlongint(&newnum) != 0)
		{
			addlongint(&sum,&newnum);
		}
		putlongint(&sum);
	}
	
	return 0;
}

int	getlongint(struct VeryLongInteger * num)
{
	char digit;
	int i,swaptemp;
	
	num->length = 0;
	while((digit = getchar()) != '\n')
	{
		num->digit[num->length++] = digit - '0';
	}
	
	for(i=0;i<num->length/2;i++)
	{
		swaptemp = num->digit[i];
		num->digit[i] = num->digit[num->length - 1 - i];
		num->digit[num->length - 1 - i] = swaptemp;
	}
	for(i=num->length;i<INTLEN;i++)
	{
		num->digit[i] = 0;
	}

	if(num->length == 1 && num->digit[0] == 0)
		return 0;
	else
		return num->length;
}

void addlongint(struct VeryLongInteger * sum , struct VeryLongInteger * add)
{
	int i;
	
	if(add->length > sum->length)
		sum->length = add->length;
		
	for(i=0;i<sum->length;i++)
	{
		sum->digit[i] += add->digit[i];
		while(sum->digit[i] > 9 && i < sum->length - 1)
		{
			sum->digit[i] -= 10;
			sum->digit[i + 1]++;
		}
	}
	if(sum->digit[sum->length - 1] > 9)
	{
		while(sum->digit[sum->length - 1] > 9)
		{
			sum->digit[sum->length]++;
			sum->digit[sum->length - 1] -= 10;
		}
		sum->length++;
	}
}

void putlongint(struct VeryLongInteger * num)
{
	int i;
	
	for(i=num->length-1;i>=0;i--)
	{
		putchar(num->digit[i] + '0');
	}
	putchar('\n');
}
