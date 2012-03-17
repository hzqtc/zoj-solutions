#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 50000;

int main()
{
	int casecount,i;
	int linecount,j;
	char text[MAX];
	int state,point1,point2;
	char processed[MAX];
	char c;
	int index;

	scanf("%d",&casecount);
	for(i=0;i<casecount;i++)
	{
		if(i > 0)
			putchar('\n');;
		
		scanf("%d",&linecount);
		getchar();
		j = 0;
		index = 0;
		while(j<linecount)
		{
			while((c = getchar()) != '\n')
			{
				text[index++] = c;
			}
			j++;
		}
		text[index] = '\0';

		index = 0;
		state = 1;//表示状态（从头还是从末尾）
		point1 = 0;//从头开始
		point2 = strlen(text) - 1;//从末尾开始
		while((c = getchar()) != '#')
		{
			if(c == 'G')
			{
				if(state == 1)
					processed[index++] = text[point1++];
				else
					processed[index++] = text[point2--];
			}
			else if(c == 'R')
				state = -state;
		}
		processed[index] = '\0';
		int len = strlen(processed);
		for(index=0;index<len;index++)
		{
			putchar(processed[index]);
			if((index + 1) % 80 == 0)
				putchar('\n');;
		}
		if(index % 80)
			putchar('\n');;
	}

	return 0;
}
