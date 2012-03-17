#include <stdio.h>
#include <string.h>

#define MAX 16
#define END(a,b) (strlen((a)) == 1 && strlen((b)) == 1 && (a)[0] == '0' && (b)[0] == '0')

int main()
{
	char * rev(char * s);

	char a[MAX],b[MAX];
	int i,maxlen;
	int re,add;
	int carry;

	while(scanf("%s %s",a,b) , !END(a,b))
	{
		rev(a);
		rev(b);
		maxlen = strlen(a);
		if(strlen(b) > maxlen)
			maxlen = strlen(b);
		for(i=strlen(a);i<maxlen;i++)
		{
			strcat(a,"0");
		}
		for(i=strlen(b);i<maxlen;i++)
		{
			strcat(b,"0");
		}
		add = 0;
		carry = 0;
		for(i=0;i<maxlen;i++)
		{
			re = a[i] - '0' + b[i] - '0' + add;
			add = 0;
			if(re > 9)
				carry++;
			while(re > 9)
			{
				add++;
				re -= 10;
			}
		}
		switch(carry)
		{
		case 0:
			printf("No carry operation.\n");
			break;
		case 1:
			printf("1 carry operation.\n");
			break;
		default:
			printf("%d carry operations.\n",carry);
			break;
		}
	}

	return 0;
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