#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char line[1024];
	int caseCount;

	scanf("%d\n", &caseCount);
	while(caseCount--)
	{
		gets(line);
		unsigned int i = 0;
		unsigned int len = strlen(line);
		while(i < len)
		{
			char c = line[i];
			int cnt = 1;
			while(line[++i] == c)
				cnt++;
			printf("%d%c", cnt, c);
		}
		putchar('\n');
	}

	return 0;
}
