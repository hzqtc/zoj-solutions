#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c;
	double out;
	int count=0;

	while(1)
	{
		scanf("%d %d %d",&a,&b,&c);
		
		if(a==0 && b==0 && c==0) 
		{
			break;
		}
		else
		{
			if(a==-1)
			{
				printf("Triangle #%d\n",++count);

				if(b >= c)
					printf("Impossible.\n\n");
				else
				{
					out=sqrt(c * c - b * b);
					printf("a = %.3lf\n\n",out);
				}
			}
			if(b==-1)
			{
				printf("Triangle #%d\n",++count);

				if(a >= c)
					printf("Impossible.\n\n");
				else
				{
					out=sqrt(c * c - a * a);
					printf("b = %.3lf\n\n",out);
				}
			}
			if(c==-1)
			{
				out=sqrt(a * a + b * b);
				printf("Triangle #%d\nc = %.3lf\n\n",++count,out);
			}
		}
	}

	return 0;
}