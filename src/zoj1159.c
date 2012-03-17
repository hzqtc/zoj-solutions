#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TELLEN	100
#define MAX  100010

char * toformatted(char *);
int cmp(const void * a,const void * b);
char * itos(int t,char * s);

int main()
{
	int telnum[MAX];
	int block,in,telcount;
	int i,j;
	char temptel[TELLEN];
	int outed;
	int repeat;

	scanf("%d",&block);

	for(in=0;in<block;in++)
	{
		if(in > 0)
			putchar('\n');

		scanf("%d",&telcount);
		for(i=0;i<telcount;i++)
		{
			scanf("%s",temptel);
			toformatted(temptel);
			telnum[i] = atol(temptel);
		}

		qsort(telnum,telcount,sizeof(int),cmp);
		i = 0;
		outed = 0;
		while(i < telcount - 1)
		{
			repeat = 1;
			j = i + 1;
			while(telnum[j] == telnum[i])
			{
				repeat++;
				j++;
			}
			if(repeat > 1)
			{
				itos(telnum[i],temptel);
				printf("%s %d\n",temptel,repeat);
				outed = 1;
			}
			i = j;
		}
		if(outed == 0)
			printf("No duplicates.\n");
	}

	return 0;
}

int cmp(const void * a,const void * b)
{
	return *(int *)a - *(int *)b;
}

char * toformatted(char * mytelnum)/*格式化电话号码，转换成标准输出形式*/
{
	char newtelnum[TELLEN];
	char c;
	int i,j,len = strlen(mytelnum);

	for(i=0,j=0;i<len;i++)
	{
		c = mytelnum[i];

		if(c >= '0' && c<= '9')
		{
			newtelnum[j++] = c;
		}
		else if(c >= 'A' && c<= 'C')
		{
			newtelnum[j++] = '2';
		}
		else if(c >= 'D' && c<= 'F')
		{
			newtelnum[j++] = '3';
		}
		else if(c >= 'G' && c<= 'I')
		{
			newtelnum[j++] = '4';
		}
		else if(c >= 'J' && c<= 'L')
		{
			newtelnum[j++] = '5';
		}
		else if(c >= 'M' && c<= 'O')
		{
			newtelnum[j++] = '6';
		}
		else if(c == 'P' || c== 'R' || c == 'S')
		{
			newtelnum[j++] = '7';
		}
		else if(c >= 'T' && c<= 'V')
		{
			newtelnum[j++] = '8';
		}
		else if(c >= 'W' && c<= 'Y')
		{
			newtelnum[j++] = '9';
		}
	}
	newtelnum[j] = '\0';

	strcpy(mytelnum,newtelnum);

	return mytelnum;
}

char * itos(int t,char * s)
{
	int i = 0;

	s[i++] = t / 1000000 + '0'; t %= 1000000;
	s[i++] = t / 100000  + '0'; t %=  100000;
	s[i++] = t / 10000   + '0'; t %=   10000; s[i++] = '-';
	s[i++] = t / 1000    + '0'; t %=    1000;
	s[i++] = t / 100     + '0'; t %=     100;
	s[i++] = t / 10      + '0'; t %=      10;
	s[i++] = t           + '0';

	s[i] = '\0';

	return s;
}