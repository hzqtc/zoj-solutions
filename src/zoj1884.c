#include <stdio.h>
#include <string.h>

#define MAX 100

char caLine[4][13]=
{
	{
		'`','1','2','3','4','5','6','7','8','9','0','-','='
	},
	{
		'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'
	},
	{
		'A','S','D','F','G','H','J','K','L',';','\''
	},
	{
		'Z','X','C','V','B','N','M',',','.','/'
	}
};

int CheckLineIndex(char,int *);

int main()
{
	char c;
	int iLineIndex,iIndex;

	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n')
		{
			putchar(c);;
		}
		else
		{
			iLineIndex = CheckLineIndex(c,&iIndex);
			putchar(caLine[iLineIndex][iIndex - 1]);
		}
	}

	return 0;
}

int CheckLineIndex(char c,int * iIndex)
{
	int i,j;

	for(i=0;i<4;i++)
	{
		if(i == 0 || i == 1)
		{
			for(j=0;j<13;j++)
			{
				if(c == caLine[i][j])
				{
					*iIndex = j;
					return i;
				}
			}
		}
		else if(i == 2)
		{
			for(j=0;j<12;j++)
			{
				if(c == caLine[i][j])
				{
					*iIndex = j;
					return i;
				}
			}

		}
		else if(i == 3)
		{
			for(j=0;j<11;j++)
			{
				if(c == caLine[i][j])
				{
					*iIndex = j;
					return i;
				}
			}

		}
	}

	return -1;
}