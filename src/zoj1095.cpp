#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

char * format(int index,char * s);
int cmp(const void * n1,const void * n2);

int main()
{
	const int MAX = 6000;
	const int LIMIT = 2000000000;
	long long hum[MAX] = {1};
	int count = 1,i,j;
	int index;
	char fstr[8];

	while(hum[count - 1] * 2 <= LIMIT)
	{
		hum[count++] = hum[count - 1] * 2;
	}
	i = count - 1;
	for(j=0;j<i;j++)
	{
		if(hum[j] * 3 <= LIMIT)
		{
			hum[count++] = hum[j] * 3;
			while(hum[count - 1] * 3 <= LIMIT)
			{
				hum[count++] = hum[count - 1] * 3;
			}
		}
	}
	i = count - 1;
	for(j=0;j<i;j++)
	{
		if(hum[j] * 5 <= LIMIT)
		{
			hum[count++] = hum[j] * 5;
			while(hum[count - 1] * 5 <= LIMIT)
			{
				hum[count++] = hum[count - 1] * 5;
			}
		}
	}
	i = count - 1;
	for(j=0;j<i;j++)
	{
		if(hum[j] * 7 <= LIMIT)
		{
			hum[count++] = hum[j] * 7;
			while(hum[count - 1] * 7 <= LIMIT)
			{
				hum[count++] = hum[count - 1] * 7;
			}
		}
	}

	qsort(hum,count,sizeof(long long),cmp);

	while(scanf("%d",&index) , index != 0)
	{
		printf("The %s humble number is %d.\n",format(index,fstr),hum[index - 1]);
	}

	return 0;
}

char * format(int index,char * s)
{
	sprintf(s,"%d",index); 

	if(index % 10 == 1 && index % 100 != 11)
		strcat(s,"st");
	else if(index % 10 == 2 && index % 100 != 12)
		strcat(s,"nd");
	else if(index % 10 == 3 && index % 100 != 13)
		strcat(s,"rd");
	else
		strcat(s,"th");

	return s;
}

int cmp(const void * n1,const void * n2)
{
	return *(long long *)n1 - *(long long *)n2;
}
