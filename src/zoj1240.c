#include <stdio.h>

int main()
{
	int repeat,re;
	int i;
	char str[50];

	scanf("%d",&repeat);

	for(re=1;re<=repeat;re++)
	{
		scanf("%s",str);

		printf("String #%d\n",re);

		i=0;
		while(str[i]!='\0')
		{
			if(str[i]=='Z')
				putchar('A');
			else
				putchar(str[i]+1);
		
			i++;
		}

		printf("\n\n");
	}

	return 0;
}