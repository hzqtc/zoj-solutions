#include <iostream>

using namespace std;

const int MAX = 16;
int store[1000][6];
int sc;

void output(int n[],int c,int begin);
int cmp(const void * a,const void * b);

int main()
{
	int num[MAX];
	int numcount,i,j;
	int ci = 0;

	while(cin>>numcount , numcount != 0)
	{
		if(ci++ > 0)
			cout<<endl;

		for(i=0;i<numcount;i++)
		{
			cin>>num[i];
		}
		sc = 0;
		output(num,numcount,numcount - 1);
		qsort(store,sc,sizeof(store[0]),cmp);
		for(i=0;i<sc;i++)
		{
			for(j=0;j<6;j++)
			{
				if(j > 0)
					cout<<' ';
				cout<<store[i][j];
			}
			cout<<endl;
		}
	}

	return 0;
}

void output(int n[],int c,int begin)
{
	int i,j;
	int index;
	int newa[MAX];

	if(c > 6)
	{
		for(i=begin;i>=0;i--)
		{
			index = 0;
			for(j = 0;j<c;j++)
			{
				if(j != i)
					newa[index++] = n[j];
			}
			output(newa,c-1,i-1);
		}
	}
	else if(c == 6)
	{
		for(i=0;i<c;i++)
		{
			store[sc][i] = n[i];
		}
		sc++;
	}
}

int cmp(const void * a,const void * b)
{
	int i = 0;

	while(*((int *)a + i) == *((int *)b + i))
		i++;

	return *((int *)a + i) - *((int *)b + i);
}