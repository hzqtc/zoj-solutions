#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
	char best_name[MAX_LEN];
	char temp_name[MAX_LEN];
	double temp_price;
	double best_price;
	int best_met;
	int temp_met;
	char temp[MAX_LEN];
	int rcount;
	int pcount;
	int i,j;
	int caseindex = 1;

	while(scanf("%d %d\n",&rcount,&pcount) , !(rcount == 0 && pcount == 0))
	{
		for(i=0;i<rcount;i++)
			gets(temp);
		best_met = -1;
		best_price = -1.0;
		for(i=0;i<pcount;i++)
		{
			gets(temp_name);
			scanf("%lf %d\n",&temp_price,&temp_met);
			for(j=0;j<temp_met;j++)
				gets(temp);
			if(temp_met > best_met || (temp_met == best_met && temp_price < best_price))
			{
				best_met = temp_met;
				best_price = temp_price;
				strcpy(best_name,temp_name);
			}
		}
		if(caseindex > 1)
			putchar('\n');
		printf("RFP #%d\n%s\n",caseindex++,best_name);
	}

	return 0;
}