#include <cstdio>

using namespace std;

const int MAX = 12;
int pos[MAX][MAX];
int m[MAX][MAX];

int getmine(int i,int j);

int main()
{
	int n;
	int i,j;
	char temp;
	int caseindex = 0;

	while(scanf("%d\n",&n) != EOF)
	{
		if(caseindex++ > 0)
			putchar('\n');

		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=n;j++)
			{
				temp = getchar();
				pos[i][j] = (temp == '.' ? 0 : 1);
			}
			getchar();
		}

		for(j=0;j<MAX;j++)
			pos[0][j] = 0;
		for(j=0;j<MAX;j++)
			pos[n + 1][j] = 0;
		for(i=0;i<MAX;i++)
			pos[i][0] = 0;
		for(i=0;i<MAX;i++)
			pos[i][n + 1] = 0;

		bool all = false;
		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=n;j++)
			{
				temp = getchar();
				m[i][j] = (temp == '.' ? 0 : 1);
				if(m[i][j] && pos[i][j])//翻开的点中含有地雷，设all为*
					all = true;
			}
			getchar();
		}

		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=n;j++)
			{
				if(all && pos[i][j])//如果此点是一个地雷
					putchar('*');
				else if(m[i][j] == 1)
				{
					if(pos[i][j] == 1)
						putchar('*');
					else
						putchar(getmine(i,j) + '0');
				}
				else
					putchar('.');
			}
			putchar('\n');
		}
	}
}

int getmine(int i,int j)
{
	int sum = 0;

	sum += pos[i - 1][j - 1];
	sum += pos[i - 1][j];
	sum += pos[i - 1][j + 1];
	sum += pos[i][j - 1];
	sum += pos[i][j + 1];
	sum += pos[i + 1][j - 1];
	sum += pos[i + 1][j];
	sum += pos[i + 1][j + 1];

	return sum;
}

