#include <stdio.h>

int main()
{
	int length,i,j;
	int trianglecount;
	
	while(scanf("%d",&length) != EOF)
	{
		trianglecount = 0;
		for(i=1;i<=length;i++)/*�����ϵ�������*/
		{
			for(j=1;j<=i;j++)
			{
				trianglecount += j;
			}
		}
		for(i=1;i<=length/2;i++)/*�����µ�������*/
		{
			for(j=1;j<=length-i*2+1;j++)
			{
				trianglecount += j;
			}
		}

		printf("%d\n",trianglecount);
	}

	return 0;
}
