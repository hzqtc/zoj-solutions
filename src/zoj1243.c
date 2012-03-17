#include <stdio.h>

#define	MAXURL	70
#define	true	1
#define	false	0

int main()
{
	int		casecount	, i;
	char	url[MAXURL]	, * p;
	int		portdef		, pathdef;
	
	scanf("%d",&casecount);
	for(i=1;i<=casecount;i++)
	{	
		scanf("%s",url);
		p = url;
		printf("URL #%d\n",i);
		
		printf("Protocol = ");
		while(*p != ':')
		{
			putchar(*(p++));
		}
		putchar('\n');
		
		portdef = false;
		pathdef = false;
		
		printf("Host     = ");
		p += 3;
		while(1)
		{
			if(*p == ':')		/*遇到port*/
			{
				printf("\nPort     = ");
				p++;
				while(*p != '\0' && *p != '/')
				{
					putchar(*p++);
				}
				portdef = true;
			}
			else if(*p == '/')	/*遇到path*/
			{
				if(portdef == false)
				{
					printf("\nPort     = <default>");
					portdef = true;
				}
				printf("\nPath     = ");
				p++;
				while(*p != '\0')
				{
					putchar(*p++);
				}
				pathdef = true;
				putchar('\n');
				break;
			}
			else if(*p == '\0')	/*URL结束*/
			{
				putchar('\n');
				break;
			}
			else
				putchar(*p++);
		}

		if(portdef == false)
			printf("Port     = <default>\n");
		if(pathdef == false)
			printf("Path     = <default>\n");
		putchar('\n');			/*空行*/
	}
	
	return 0;
}