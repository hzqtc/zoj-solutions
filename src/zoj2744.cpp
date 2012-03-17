#include <cstdio>
#include <cstring>

/*
 *当我们找到一个回文的时候，只要向两端扩展判断两个字符，就可以知道这个串是否为回文。
 *由此我们可以用这个向两边扩展的方法解题。把已经找到的回文储存起来，然后逐步扩展。
 */
using namespace std;

const int MAX = 5000;
bool yes[MAX][MAX];

int main()
{
	char str[MAX + 10];

	while(scanf("%s",str) != EOF)
	{
		int len = strlen(str);
		int count = len;
		int i,j;
		
		for(i=0;i<MAX;i++)
			yes[i][i] = true;
		
		for(i=len-2;i>=0;i--)
		{
			for(j=i+1;j<len;j++)
			{
				if(str[i] == str[j])
				{
					if(j > i + 1)
						yes[i][j] = yes[i + 1][j - 1];
					else
						yes[i][j] = true;
				}
				else
					yes[i][j] = false;
				
				if(yes[i][j])
					count++;
			}
		}
		printf("%d\n",count);
	}

	return 0;
}

