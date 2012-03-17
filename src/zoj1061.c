#include <stdio.h>
#include <string.h>

#define MAX_CMD		10
#define MAX_URL		80
#define MAX_STACK	100

int main()
{
	int		CaseCount,i;
	char	command[MAX_CMD],currenturl[MAX_URL];
	char	backward[MAX_STACK][MAX_URL],forward[MAX_STACK][MAX_URL];
	int		backstackcount,forstackcount;
	
	scanf("%d",&CaseCount);
	
	for(i=0;i<CaseCount;i++)
	{
		if(i > 0)
			putchar('\n');
		
		backstackcount = 0;
		forstackcount = 0;
		strcpy(currenturl,"http://www.acm.org/");
		
		while(scanf("%s",command) , strcmp(command,"QUIT") != 0)
		{
			if(strcmp(command,"VISIT") == 0)
			{
				strcpy(backward[backstackcount++],currenturl);
				forstackcount = 0;
				scanf("%s",currenturl);
				printf("%s\n",currenturl);
			}
			else if(strcmp(command,"BACK") == 0)
			{
				if(backstackcount == 0)
					printf("Ignored\n");
				else
				{
					strcpy(forward[forstackcount++],currenturl);
					strcpy(currenturl,backward[--backstackcount]);
					printf("%s\n",currenturl);
				}
			}
			else if(strcmp(command,"FORWARD") == 0)
			{
				if(forstackcount == 0)
					printf("Ignored\n");
				else
				{
					strcpy(backward[backstackcount++],currenturl);
					strcpy(currenturl,forward[--forstackcount]);
					printf("%s\n",currenturl);
				}
			}
		}
	}
	
	return 0;
}
