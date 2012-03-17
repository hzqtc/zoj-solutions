#include <stdio.h>
#include <string.h>

int main()
{
	char filename[100][80];
	char query[80];
	int qi;
	char part[80][80];
	int partcount;
	char * qp;
	char * temp;
	int fc,qc;
	int find;
	int i,j,k;
	int cindex = 0;
	int searched;

	while(scanf("%d",&fc) != EOF)
	{
		if(cindex++ > 0)
			putchar('\n');

		for(i=0;i<fc;i++)
		{
			scanf("%s",filename[i]);
		}

		scanf("%d",&qc);
		for(i=0;i<qc;i++)
		{
			scanf("%s",query);
			if(strlen(query) == 1 && query[0] == '*')
			{
				for(j=0;j<fc;j++)
				{
					if(j > 0)
						printf(", ");
					printf("%s",filename[j]);
				}
				putchar('\n');
				continue;
			}

			qi = partcount = 0;
			for(j=0;j<strlen(query);j++)
			{
				if(query[j] != '*')
					part[partcount][qi++] = query[j];
				else
				{
					part[partcount][qi] = '\0';
					if(strlen(part[partcount]) != 0)
						partcount++;
					qi = 0;
				}
			}
			part[partcount][qi] = '\0';
			if(strlen(part[partcount]) != 0)
				partcount++;

			find = 0;
			for(j=0;j<fc;j++)
			{
				qp = filename[j];
				for(k=0;k<partcount;k++)
				{
					if((temp = strstr(qp,part[k])) != NULL)
					{
						qp = temp + strlen(part[k]);
						searched = 1;
						if(k == 0)
						{
							if((temp != filename[j]) && (query[0] != '*'))
								searched = 0;
						}
						if(k == partcount - 1)
						{
							while((temp = strstr(qp,part[k])) != NULL)
							{
								qp = temp + strlen(part[k]);
							}
							if((qp != filename[j] + strlen(filename[j])) && (query[strlen(query) - 1] != '*'))
								searched = 0;
						}
					}
					else
						searched = 0;

					if(searched == 0)
						break;
				}
				if(searched == 1)
				{
					if(find > 0)
						printf(", ");
					find++;
					printf("%s",filename[j]);
				}
			}
			if(find == 0)
				printf("FILE NOT FOUND\n");
			else
				putchar('\n');
		}
	}

	return 0;
}
