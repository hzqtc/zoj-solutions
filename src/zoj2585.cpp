#include <cstdio>
#include <cstring>

#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

int main()
{
	const int LEN = 50;
	char w1[LEN],w2[LEN];
	int alpha[26];
	int casecount,caseindex;
	int i;
	int move;
	
	scanf("%d\n",&casecount);
	
	for(caseindex=1;caseindex<=casecount;caseindex++)
	{
		for(i=0;i<26;i++)
			alpha[i] = 0;
			
		gets(w1);
		for(i=0;i<strlen(w1);i++)
			alpha[w1[i] - 'a']++;
			
		gets(w2);
		for(i=0;i<strlen(w2);i++)
			alpha[w2[i] - 'a']--;
			
		move = 0;
		for(i=0;i<26;i++)
			move += ABS(alpha[i]);
		printf("Case #%d:  %d\n",caseindex,move);
	}
	
	return 0;
}

