#include <stdio.h>

int main()
{
	int n;

	while(scanf("%d",&n) != EOF)
	{
		if (n % 4 == 2)
			puts("yes");
		else
			puts("no");
	}

	return 0;
}

