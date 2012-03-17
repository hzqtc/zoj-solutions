#include <stdio.h>
#include <stdlib.h>

#define OFF 0
#define ON 1

int main()
{
	int count,i;
	int * num;
	int times1,times2;

	while((scanf("%d",&count)) != EOF)
	{
		if((num=(int *)calloc(count,sizeof(int)))!=NULL)
		{
			for(i=0;i<count;i++)
			{
				scanf("%d",&num[i]);
			}
		
			times1 = times2 = 0;
			for(i=0;i<count;i++)
			{
				if(i %2 == 0)/*第一种奇数开，偶数关(times1)；第二种奇数关，偶数开(times2)。*/
				{
					if(num[i] == ON) 
						times1++;
					else 
						times2++;
				}
				else
				{
					if(num[i] == OFF) 
						times1++;
					else
						times2++;
				}
			}

			printf("%d\n",(times1 > times2) ? times2 : times1);
		}
	}

	return 0;
}