#include <stdio.h>
#include <stdlib.h>

#define	unlocked	0
#define	locked		1

int main()
{
	int repeat,re;
	int n,i,j,count;
	int * cell;

	scanf("%d",&repeat);
	for(re=1;re<=repeat;re++)
	{
		scanf("%d",&n);
		
		if((cell=(int *)calloc(n,sizeof(int)))!=NULL)
		{
			for(i=0;i<n;i++)/*��һ�֣�˳���ʼ��cell��ȫ��Ϊ0����ʾȫ������*/
			{
				cell[i]=unlocked;
			}

			for(i=2;i<=n;i++)/*�ӵڶ��ֿ�ʼ��*/
			{
				for(j=1;j<=n;j++)
				{
					if(j % i == 0)
					{
						if(cell[j-1]==unlocked)
							cell[j-1]=locked;
						else
							cell[j-1]=unlocked;
					}
				}
			}

			count=0;
			for(i=0;i<n;i++)
			{
				if(cell[i]==unlocked) count++;
			}
			printf("%d\n",count);
		}
	}

	return 0;
}