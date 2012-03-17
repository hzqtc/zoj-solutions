#include <stdio.h>

int main()
{
	int result,i,temp;
	char c,str[1000];

	while(1)
	{
		i=0;
		
		while((c=getchar())!='\n')/*get a string of numbers*/
		{
			str[i++]=c;
		}
		str[i]='\0';

		if(str[0]=='0' && i==1)/*if the string has only a "0" then end*/ 
		{
			break;
		}
		else/*get result*/
		{
			result=0;
			i=0;

			while(str[i]!='\0')
			{
				result+=(str[i]-'0');
				i++;
			}

			while(result>=10)
			{
				temp=result;
				result=0;

				while(temp)
				{
					result+=temp%10;
					temp/=10;
				}
			}

			printf("%d\n",result);
		}
	}

	return 0; 
}