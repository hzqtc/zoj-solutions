#include <stdio.h>

int main()
{
	int n,m;
	int index,count;
	int blockcount,i;
	int a,b;
	
	scanf("%d",&blockcount);
	
	for(i=0;i<blockcount;i++)
	{
		if(i > 0)/*there should be a blank line between output blocks*/
			putchar('\n');
		index = 0;
		while(scanf("%d %d",&n,&m) , !(n == 0 && m == 0))
		{
			index++;
			count = 0;
			for(a=1;a<n-1;a++)
			{
				for(b=a+1;b<n;b++)
				{
					if((a * a + b * b + m) % (a * b) == 0)
					{
						count++;
					}
				}
			}
			printf("Case %d: %d\n",index,count);
		}
	}
	
	return 0;
}
