#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX	1000
#define LEN	100


int cmp(const void * a,const void * b);

int main()
{
	int codecount = 0,caseindex = 1;
	char code[MAX][LEN];
	int i;
	int prefix;

	while(scanf("%s",code[codecount]) != EOF)
	{
		if(strcmp(code[codecount],"9"))
			codecount++;
		else
		{
			qsort(code,codecount,sizeof(char) * LEN,cmp);
			prefix = 0;
			i = 0;
			while(i < codecount - 1)
			{
				if(strstr(code[i + 1],code[i]) != NULL)
				{
					prefix = 1;
					break;
				}
				i++;
			}
			if(prefix == 1)
				printf("Set %d is not immediately decodable\n",caseindex++);
			else
				printf("Set %d is immediately decodable\n",caseindex++);
			codecount = 0;
		}
	}
}

int cmp(const void * a,const void * b)
{
	return strcmp((char *)a,(char *)b);
}
