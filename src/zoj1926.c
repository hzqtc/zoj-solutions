/*Wrong Answer*/
#include <stdio.h>
#include <string.h>

#define MAX	10

int main()
{
	int upbond = 11,downbond = 0;
	int guess;
	char tip1[MAX],tip2[MAX];
	int honest;
	
	while(scanf("%d",&guess) , guess != 0)
	{
		scanf("%s %s",tip1,tip2);
		honest = 1;
		
		if(strcmp(tip1,"too") == 0)
		{
			if(strcmp(tip2,"high") == 0)
			{
				if(guess < upbond)
					upbond = guess;
			}
			else if(strcmp(tip2,"low") == 0)
			{
				if(guess > downbond)
					downbond = guess;
			}
		}
		else if(strcmp(tip1,"right") == 0 && strcmp(tip2,"on") == 0)
		{
			if(guess > downbond && guess < upbond)
				puts("Stan may be honest");
			else
				puts("Stan is dishonest");
			
			upbond = 11;
			downbond = 0;
		}
	}
	
	return 0;
}
