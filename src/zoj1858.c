/* 1 represents B, F, P, or V
 * 2 represents C, G, J, K, Q, S, X, or Z
 * 3 represents D or T
 * 4 represents L
 * 5 represents M or N
 * 6 represents R
 * The letters A, E, I, O, U, H, W, and Y are not represented in Soundex coding
 */
#include <stdio.h>
#include <string.h>

#define LEN	25

int main()
{
	char word[LEN];
	int i,num;
	
	while(scanf("%s",word) != EOF)
	{
		num = -1;
		for(i=0;i<strlen(word);i++)
		{
			if(word[i] == 'B' || word[i] == 'F' || word[i] == 'P' || word[i] == 'V')
			{
				if(num != 1)
				{
					num = 1;
					printf("%d",num);
				}
			}
			else if(word[i] == 'C' || word[i] == 'G' || word[i] == 'J' || word[i] == 'K' || word[i] == 'Q' || word[i] == 'S' || word[i] == 'X' || word[i] == 'Z')
			{
				if(num != 2)
				{
					num = 2;
					printf("%d",num);
				}
			}
			else if(word[i] == 'D' || word[i] == 'T')
			{
				if(num != 3)
				{
					num = 3;
					printf("%d",num);
				}
			}
			else if(word[i] == 'L')
			{
				if(num != 4)
				{
					num = 4;
					printf("%d",num);
				}
			}
			else if(word[i] == 'M' || word[i] == 'N')
			{
				if(num != 5)
				{
					num = 5;
					printf("%d",num);
				}
			}
			else if(word[i] == 'R')
			{
				if(num != 6)
				{
					num = 6;
					printf("%d",num);
				}
			}
			else
			{
				num = -1;
			}
		}
		putchar('\n');
	}
	
	return 0;
}
