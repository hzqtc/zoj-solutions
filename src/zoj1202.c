#include <stdio.h>
#include <stdlib.h>

#define MAXSAME 20

struct samecap
{
	int cap;
	int count;
}same[MAXSAME];

int choose(int n,int m);
void addsame(int num);
int jiecheng(int n);

int main()
{
	int coffercount,diamondcount,selection;
	int * coffer;
	int i,j;

	while(scanf("%d",&coffercount) != EOF)
	{
		if((coffer=(int *)calloc(coffercount,sizeof(int))) != NULL)
		{
			for(i=0;i<MAXSAME;i++)
			{
				same[i].cap=0;
				same[i].count=0;
			}
			diamondcount=0;

			for(i=0;i<coffercount;i++)
			{
				scanf("%d",&coffer[i]);
				diamondcount += coffer[i];

				for(j=0;j<i;j++)
				{
					if(coffer[j] == coffer[i]) 
					{
						addsame(coffer[i]);
						break;
					}
				}
			}

			selection=1;
			for(i=0;i<coffercount - 1;i++)
			{
				diamondcount -= ((i > 0) ? coffer[i-1] : 0);
				selection *= choose(diamondcount,coffer[i]);
			}

			for(i=0;i<MAXSAME;i++)
			{
				selection /= jiecheng(same[i].count + 1);
			}

			printf("%d\n",selection);
		}
	}

	return 0;
}

int choose(int n,int m)
{
	int i,re=1;

	for(i=n;i>=n - m + 1;i--)
	{
		re *= i;
	}

	for(i=2;i<=m;i++)
	{
		re /= i;
	}

	return re;
}

void addsame(int num)
{
	int i;

	for(i=0;i<MAXSAME;i++)
	{
		if(same[i].cap == num)
		{
			same[i].count++;
			break;
		}
		else if(same[i].cap == 0)
		{
			same[i].cap = num;
			same[i].count++;
			break;
		}
	}
}

int jiecheng(int n)
{
	int re=1,i;
	
	for(i=2;i<=n;i++)
	{
		re *= i;
	}

	return re;
}