#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_MAX	16
#define LINE_MAX	50
#define ENTY_MAX	100010

#define TRUE		1
#define FALSE		0

struct DictEnty
{
	char En[WORD_MAX];
	char Fm[WORD_MAX];
}enty[ENTY_MAX];

struct Loc
{
	int begin;
	int end;
}aloc[26];

int getline(char * s);
int cmp(const void * a,const void * b);
int cmpsearch(const void * a,const void * b);

int main()
{
	char line[LINE_MAX],fmwrd[WORD_MAX];
	int count = 0;
	int i;
	int locindex;
	
	while(getline(line) != 0)/*get engish word and fmwrd from a line, these will form a dictionary*/
	{
		int index;
		index = (int)(strchr(line,' ') - line);
		strncpy(enty[count].En,line,index);
		strncpy(enty[count].Fm,line + index + 1,strlen(line) - index);
		count++;
	}
	qsort(enty,count,sizeof(struct DictEnty),cmp);/*sort the dictionary*/

	locindex = 0;
	for(i=0;i<count;i++)/*this step will locate the begin and end index of each alpha(from 'a' to 'z')*/
	{
		if(aloc[enty[i].Fm[0] - 'a'].begin == 0)
		{
			aloc[enty[i].Fm[0] - 'a'].begin = i;
		}
		if(enty[i].Fm[0] - 'a' > locindex )
			aloc[locindex].end = i - 1;
		locindex = enty[i].Fm[0] - 'a';
	}
	aloc[locindex].end = count - 1;

	while(scanf("%s",fmwrd) != EOF)
	{
		int index = fmwrd[0] - 'a';
		struct DictEnty * find;

		find = (struct DictEnty *)bsearch(fmwrd,enty + aloc[index].begin,aloc[index].end - aloc[index].begin + 1,sizeof(struct DictEnty),cmpsearch);
		if(find != NULL)
			printf("%s\n",find->En);
		else
			printf("eh\n");
	}
	
	return 0;
}

int getline(char * s)
{
	int i = 0;
	char c;
	
	while((c = getchar()) != '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	
	return i;
}

int cmp(const void * a,const void * b)
{
	return strcmp(((struct DictEnty *)a)->Fm,((struct DictEnty *)b)->Fm);
}

int cmpsearch(const void * a,const void * b)
{
	return strcmp((char *)a,((struct DictEnty *)b)->Fm);
}
