#include <stdio.h>
#include <string.h>

#define MsgerMax	 8 
#define MsgMax		32
#define RIGHT		 1
#define LEFT		-1

int main()
{
	char * rotate(char * s,int dir);
	char * swap(char * s);
	char * numcre(char * s,int n);
	char * rev(char * s);

	int casecount,i;
	char msger[MsgerMax],msg[MsgMax];
	int j;

	scanf("%d",&casecount);
	for(i=0;i<casecount;i++)
	{
		scanf("%s %s",msger,msg);
		for(j=strlen(msger)-1;j>=0;j--)
		{
			switch(msger[j])
			{
				case 'J':
					rotate(msg,RIGHT);/*move right*/
					break;
				case 'C':
					rotate(msg,LEFT);/*move left*/
					break;
				case 'E':
					swap(msg);/*swap two parts*/
					break;
				case 'A':
					rev(msg);/*reverse*/
					break;
				case 'P':
					numcre(msg,-1);/*all digit decrease*/
					break;
				case 'M':
					numcre(msg,1);/*all digit increase*/
					break;
				default:
					break;
			}
		}
		puts(msg);
	}

	return 0;
}

char * rotate(char * s,int dir)
{
	int i;
	char temp;

	if(dir == RIGHT)
	{
		temp = s[strlen(s) - 1];
		for(i=strlen(s)-1;i>0;i--)
		{
			s[i] = s[i - 1];
		}
		s[0] = temp;
	}
	else if(dir == LEFT)
	{
		temp = s[0];
		for(i=0;i<strlen(s)-1;i++)
		{
			s[i] = s[i + 1];
		}
		s[strlen(s) - 1] = temp;
	}

	return s;
}
char * swap(char * s)
{
	char temp;
	int len = strlen(s);
	int i;

	if(len % 2 == 0)
	{
		for(i = 0;i<len/2;i++)
		{
			temp = s[i];
			s[i] = s[i + len / 2];
			s[i + len / 2] = temp;
		}
	}
	else
	{
		for(i = 0;i<len/2;i++)
		{
			temp = s[i];
			s[i] = s[i + len / 2 + 1];
			s[i + len / 2 + 1] = temp;
		}
	}
	return s;
}
char * numcre(char * s,int n)
{
	int i;

	for(i = 0;i<strlen(s);i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			s[i] += n;
			if(s[i] < '0')
				s[i] = '9';
			else if(s[i] > '9')
				s[i] = '0';
		}
	}

	return s;
}

char * rev(char * s)
{
	int i;
	char temp;

	for(i=0;i<strlen(s)/2;i++)
	{
		temp = s[i];
		s[i] = s[strlen(s) - 1 - i];
		s[strlen(s) - 1 - i] = temp;
	}

	return s;
}