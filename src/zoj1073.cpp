#include <cstdio>
#include <cstring>

using namespace std;

bool belong(int a[],int b[],int len);

int main()
{
	const int LEN = 64;
	char s[LEN];
	int num[LEN];
	int multi[LEN];
	bool ok;
	
	while(scanf("%s",s) != EOF)
	{
		int len,i,j;
		
		len = strlen(s);
		for(i=0;i<len;i++)
		{
			num[i] = s[len - 1 - i] - '0';
		}
		ok = true;
		for(i=2;i<=len;i++)
		{
			for(j=0;j<len;j++)
			{
				multi[j] = 0;
			}
			for(j=0;j<len;j++)
			{
				multi[j] += num[j] * i;
				while(multi[j] > 9)
				{
					multi[j] -= 10;
					multi[j + 1]++;
					if(j + 1 > len - 1)
					{
						printf("%s is not cyclic\n",s);
						ok = false;
						break;
					}
				}
				if(ok == false)
					break;
			}
			if(ok == false)
				break;
			else
			{
				if(belong(num,multi,len) == false)
				{
					printf("%s is not cyclic\n",s);
					ok = false;
					break;
				}
			}
		}
		if(ok == true)
			printf("%s is cyclic\n",s);
	}
	
	return 0;
}

bool belong(int a[],int b[],int len)
{
	int i,j;
	int begin;
	int match;

	for(begin=0;begin<len;begin++)
	{
		if(b[begin] == a[0])
		{
			match = true;
			for(i=0,j=begin;j<len;j++,i++)
			{
				if(a[i] != b[j])
				{
					match = false;
					break;
				}
			}
			if(match == false)
				continue;
			for(j=0;j<begin;j++,i++)
			{
				if(a[i] != b[j])
				{
					match = false;
					break;
				}
			}
			if(match == true)
				return true;
		}
	}
	
	return false;
}
