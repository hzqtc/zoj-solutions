#include <stdio.h>

#define MAXLENGTH	51
#define MAXCOUNT	101

struct DNA
{
	char	str[MAXLENGTH];
	int		sortgrade;
}dna[MAXCOUNT];

void getsortgrade(struct DNA *,int);

int main()
{
	int casecount,i;
	int len,count,j,printcount,grade;
	
	scanf("%d",&casecount);
	
	for(i=0;i<casecount;i++)
	{
		if(i > 0)
			putchar('\n');
			
		scanf("%d %d",&len,&count);
		for(j=0;j<count;j++)
		{
			scanf("%s",dna[j].str);
			getsortgrade(&dna[j],len);
		}
		
		printcount = 0;
		grade = 0;
		while(printcount < count)
		{
			for(j=0;j<count;j++)
			{
				if(dna[j].sortgrade == grade)
				{
					printf("%s\n",dna[j].str);
					printcount++;
				}
			}
			grade++;
		}
	}
	
	return 0;
}

void getsortgrade(struct DNA * sort,int length)
{
	int i,j;
	
	sort->sortgrade = 0;
	for(i = 0;i < length - 1;i++)
	{
		for(j = i + 1;j < length;j++)
		{
			if(sort->str[i] > sort->str[j])
				sort->sortgrade++;
		}
	}
}