#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int cmp(const void* a,const void* b);

int main()
{
	int seqlen;
	const int MAX = 110;
	int t;
	int num[MAX];
	
	while(cin >> seqlen , seqlen > 0)
	{
		map<int,int> seq;
		int numcount = 0;
					
		for(int i = 0;i<seqlen;i++)
		{
			cin >> t;
			seq[t]++;
			if(seq[t] == 1)
				num[numcount++] = t;
		}
		qsort(num,numcount,sizeof(int),cmp);
		cout << num[0];
		for(int i = 1;i<numcount;i++)
			cout << ' ' << num[i];
		cout << endl;
	}
	
	return 0;
}

int cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

