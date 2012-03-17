#include <stdio.h>
#include <string.h>

#define MAX		1000

int main()
{
	char word[MAX];
	int index = 0;
	char c;

	char format(char * c);
	
	while((c = getchar()) != EOF)
	{
		if(c >= 'A' && c <= 'Z')
		{
			word[index++] = format(&c);
		}
		else
		{
			word[index] = '\0';
			if(strcmp(word,"ZIYJADIKPO") == 0)
				break;
			else if(strcmp(word,"NOVMO") * strcmp(word,"ZIY"))
			{
				printf("%s",word);
				putchar(c);
			}
			index = 0;
		}
	}	

	return 0;
}

char format(char * c)
{
	*c -= 5;
	if(*c > 'Z')
		*c -= 26;
	if(*c < 'A')
		*c += 26;
		
	return *c;
}
