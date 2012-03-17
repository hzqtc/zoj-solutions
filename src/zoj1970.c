#include <stdio.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define MAX		100000

int main()
{
	char subseq[MAX],seq[MAX];
	int  i;
	char * begin;
	char * find;
	int found;
	
	while(scanf("%s %s",subseq,seq) != EOF)
	{
		begin = seq;
		found = TRUE;
		for(i=0;i<strlen(subseq);i++)
		{
			if((find = strchr(begin,subseq[i])) != NULL)
				begin = find + 1;
			else
			{
				found = FALSE;
				break;
			}
		}
		if(found == TRUE)
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}
