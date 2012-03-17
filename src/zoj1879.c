#include <stdio.h>

#define MAX	3000

int main()
{
	int seqsize,i;
	int diff[MAX];
	int num1,num2,index;
	int flag;
	
	void init(int * ia,int size);
	
	while(scanf("%d",&seqsize) != EOF)
	{
		init(diff,seqsize);
		scanf("%d",&num1);
		flag = 1;
		for(i=1;i<seqsize;i++)
		{
			scanf("%d",&num2);
			if(flag == 1)
			{
				index = num2 > num1 ? num2 - num1 : num1 - num2;
				if(index > seqsize - 1 || index < 1 || diff[index] == 1)
					flag = 0;
				else
				{
					diff[index] = 1;
					num1 = num2;
				}
			}
		}
		if(flag == 1)
			puts("Jolly");
		else
			puts("Not jolly");
	}
	
	return 0;
}

void init(int * ia,int size)
{
	int i;
	
	for(i=0;i<size;i++)
	{
		ia[i] = 0;
	}
}
