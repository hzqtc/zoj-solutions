/*i=4k		,	(2k,2k);
 *i=4k-3	,	(2k-1,2k-1);
 *i=4k-2	,	(2k,2k-2);
 *i=4k-1	,	(2k+1,2k-1).
 */
#include <stdio.h>

int main()
{
	int count,i;
	int x,y;

	scanf("%d",&count);

	for(i=0;i<count;i++)
	{
		scanf("%d %d",&x,&y);

		if(x >= 0 && y >= 0)
		{
			if(x == y && x % 2 == 0)
			{
				printf("%d\n",2 * x);
			} 
			else if(x == y && (x + 1) % 2 == 0)
			{
				printf("%d\n",2 * x - 1);
			}
			else if(x == y + 2 && x % 2 == 0)
			{
				printf("%d\n",2 * x - 2);
			}
			else if(x == y + 2 && (x - 1) % 2 == 0)
			{
				printf("%d\n",2 * x - 3);
			}
			else
			{
				puts("No Number");
			}
		}
		else
		{
			puts("No Number");
		}
	}

	return 0;
}