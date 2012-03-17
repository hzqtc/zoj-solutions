#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAX = 100;
struct category
{
	int total_cou;
	int min_cou;
	int match;
	int cou;
}cate[MAX];

int cmp(const void* a,const void* b);

int main()
{
	int coursecount,catecount;
	int course[MAX];
	int i;
	bool meet;
	
	while(scanf("%d",&coursecount) , coursecount != 0)
	{
		scanf("%d",&catecount);
		for(i=0;i<coursecount;i++)
			scanf("%d",course + i);
		qsort(course,coursecount,sizeof(int),cmp);
		meet = true;

		for(i=0;i<catecount;i++)
		{
			scanf("%d%d",&cate[i].total_cou,&cate[i].min_cou);
			cate[i].match = 0;
			for(int j = 0;j<cate[i].total_cou;j++)
			{
				scanf("%d",&cate[i].cou);
				if(meet == true && bsearch(&cate[i].cou,course,coursecount,sizeof(int),cmp) != NULL)
					cate[i].match++;
			}
			if(cate[i].match < cate[i].min_cou)
				meet = false;
		}
		if(meet == true)
			puts("yes");
		else
			puts("no");
	}

	return 0;
}

int cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}