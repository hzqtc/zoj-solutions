#include <stdio.h>
#include <string.h>

#define MAX	128

int main()
{
	char correct[MAX],typed[MAX],index;
	int pertime,totaltime;
	int casecount,i;
	
	scanf("%d",&casecount);
	for(i=0;i<casecount;i++)
	{
		scanf("%d",&pertime);
		getchar();
		gets(correct);
		gets(typed);
		
		index = 0;
		if(strcmp(correct,typed) == 0)
			printf("0\n");
		else
		{
			while(correct[index] == typed[index])
				index++;

			totaltime = (strlen(correct) - index + strlen(typed) - index) * pertime;
			
			printf("%d\n",totaltime);
		}
	}
	
	return 0;
}
