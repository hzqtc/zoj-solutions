#include <stdio.h>

int main()
{
	int num1,num2;
	int sum;
	int casecount,i;
	
	int reverse(int orinum);
	
	scanf("%d",&casecount);
	for(i=0;i<casecount;i++)
	{
		scanf("%d %d",&num1,&num2);
		sum = reverse(reverse(num1) + reverse(num2));
		printf("%d\n",sum);
	}
	
	return 0;
}

int reverse(int orinum)
{
	int rev = 0;
	
	while(orinum)
	{
		rev = rev * 10 + orinum % 10;
		orinum /= 10;
	}
	
	return rev;
}
