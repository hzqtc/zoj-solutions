#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX		25
#define LEN		100

int cmp(const void * a,const void * b);
int cmp_search(const void * a,const void * b);

struct candidate
{
	char name[LEN];
	char party[LEN];
	int vote;
};

int main()
{
	int candcount;
	struct candidate cand[MAX],* search,* max,swap;
	int votecount;
	char s[LEN];
	int i,j;
	int havemax;
	int maxvote;
	

	while(scanf("%d",&candcount) != EOF)
	{
		gets(s);
		for(i=0;i<candcount;i++)
		{
			gets(cand[i].name);
			gets(cand[i].party);
			cand[i].vote = 0;
		}

		qsort(cand,candcount,sizeof(struct candidate),cmp);

		scanf("%d",&votecount);
		max = NULL;
		maxvote = 0;
		havemax = 0;
		gets(s);

		while(votecount--)
		{
			gets(s);
			if((search = (struct candidate *)bsearch(s,cand,candcount,sizeof(struct candidate),cmp_search)) != NULL)
			{
				search->vote++;
				if(max == NULL || maxvote < search->vote)
				{
					max = search;
					maxvote = search->vote;
					havemax = 1;
				}
				else if(maxvote == search->vote)
					havemax = 0;
			}
		}

		if(havemax == 1)
			printf("%s\n",max->party);
		else
			puts("tie");
	}

	return 0;
}

int cmp(const void * a,const void * b)
{
	return strcmp(((struct candidate *)a)->name,((struct candidate *)b)->name);
}

int cmp_search(const void * a,const void * b)
{
	return strcmp((char *)a,((struct candidate *)b)->name);
}
