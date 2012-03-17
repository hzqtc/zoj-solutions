#include <stdio.h>
#include <string.h>

#define MAX		16
#define LEN		110

int main()
{
	char ciphertext[LEN];
	char plaintext[MAX][LEN];
	char keyword[MAX];
	int i,j;
	int len;
	char c;
	int index;

	while(scanf("%s",keyword) , strcmp(keyword,"THEEND"))
	{
		scanf("%s",ciphertext);
		len = strlen(ciphertext) / strlen(keyword);
		for(c = 'A',index=0;c<='Z';c++)
		{
			for(i=0;i<strlen(keyword);i++)
			{
				if(keyword[i] == c)
				{
					strncpy(plaintext[i],ciphertext + (index++) * len,len);
					plaintext[i][len] = '\0';
				}
			}
		}
		for(i=0;i<len;i++)
		{
			for(j=0;j<strlen(keyword);j++)
			{
				putchar(plaintext[j][i]);
			}
		}
		putchar('\n');;
	}

	return 0;
}