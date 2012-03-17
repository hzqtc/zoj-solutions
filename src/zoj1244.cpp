#include <cstdio>

using namespace std;

int main()
{
	const int MAX = 26;
	bool var[MAX];
	char c1,c2;
	int linecount;
	int caseindex = 1;

	while(scanf("%d\n",&linecount) , linecount > 0)
	{
			
		var[0] = true;
		for(int i = 1;i<MAX;i++)
			var[i] = false;

		while(linecount--)
		{
			scanf("%c = %c\n",&c1,&c2);
			var[c1 - 'a'] = var[c2 - 'a'];
		}

		printf("Program #%d\n",caseindex++);
		bool printed = false;
		for(int i = 0;i<MAX;i++)
		{
			if(var[i] == true)
			{
				printed = true;
				printf("%c ",i + 'a');
			}
		}
		if(printed == false)
			printf("none\n");
		else
			putchar('\n');
		putchar('\n');
	}

	return 0;
}

