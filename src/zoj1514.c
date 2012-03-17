#include <stdio.h>

#define MAX	20000

int main()
{
	int ticket[MAX],index;
	int oriticket,audience,ticketnumber,fake;
	
	while(scanf("%d %d",&oriticket,&audience) , oriticket != 0 && audience != 0)
	{
		for(index=0;index<MAX;index++)
		{
			ticket[index] = 0;
		}
		fake = 0;
		
		for(index=0;index<audience;index++)
		{
			scanf("%d",&ticketnumber);
			ticket[ticketnumber]++;
			if(ticket[ticketnumber] == 2)/*the first time "clone" appear*/
				fake++;
		}
		printf("%d\n",fake);
	}
	
	return 0;
}
