#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int cmp(const void* a,const void* b);

const int MAX = 110;

int main()
{
	char ciper[MAX],original[MAX];
	int pair1[26],pair2[26];
	int i;

	while(scanf("%s %s",ciper,original) != EOF)
	{
		if(strlen(ciper) != strlen(original))
		{
			puts("NO");
			continue;
		}

		for(i=0;i<26;i++)
			pair1[i] = pair2[i] = 0;
		for(i=0;i<strlen(ciper);i++)
		{
			pair1[ciper[i] - 'A']++;
			pair2[original[i] - 'A']++;
		}
		qsort(pair1,26,sizeof(int),cmp);
		qsort(pair2,26,sizeof(int),cmp);

		for(i=0;i<26;i++)
		{
			if(pair1[i] != pair2[i])
				break;
		}
		if(i == 26)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}

int cmp(const void* a,const void* b)
{
	return *((int*)a) - *((int*)b);
}

