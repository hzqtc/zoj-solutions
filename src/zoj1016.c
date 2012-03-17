#include <stdio.h>

#define LeftPar		 1
#define RightPar	-1
#define None		 0
#define MAX			 100
/*不知道要多大的容量来存储，所以不通过就尽量增加*/

void InitSeq(int *);

int main()
{
	int sequence[MAX];
	int CaseCount,i,DataCount,j;
	int leftparcount,temp,now,k;/*now is the index of the next sequence element*/
	int rightparcount,first;
	
	scanf("%d",&CaseCount);
	 
	for(i=0;i<CaseCount;i++)
	{
		InitSeq(sequence);/*set all elements in sequence to None*/
		now = 0;
		leftparcount = 0;
		scanf("%d",&DataCount);
		
		for(j=0;j<DataCount;j++)/*read in the parentheses in order*/
		{
			scanf("%d",&temp);
			
			for(k=0;k < temp - leftparcount;k++,now++)/*add left parentheses*/
			{
				sequence[now] = LeftPar;
			}
			leftparcount = temp;
			sequence[now++] = RightPar;
		}
	
		first = 1;
		for(j=0;j<now;j++)/*print the sequence in W-sequence*/
		{
			if(sequence[j] == RightPar)
			{
				leftparcount = 0;
				rightparcount = 1;
				for(k = j - 1;k>=0;k--)
				{
					if(sequence[k] == LeftPar)
					{
						if(leftparcount == 0)
						{
							if(first == 1)
							{
								printf("%d",rightparcount);
								first = 0;
							}
							else
								printf(" %d",rightparcount);
								
							break;
						}
						else
							leftparcount--;/*the left parentheses needed decrease*/
					}
					else
					{
						leftparcount++;/*the left parentheses needed increase*/
						rightparcount++;
					}
				}
			}
		}
		putchar('\n');
	}
	
	return 0;
}

void InitSeq(int * seq)
{
	int i;
	
	for(i=0;i<20;i++)
	{
		seq[i] = None;
	}
}
