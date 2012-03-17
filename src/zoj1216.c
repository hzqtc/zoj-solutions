#include <stdio.h>

int main()
{
	long cardnumber;
	double length;
	long i;
	
	printf("# Cards  Overhang\n");

	while(scanf("%d",&cardnumber) != EOF)
	{
		length = 0;
		for(i=1;i<=cardnumber;i++)
		{
			length += (double)1 / (double)(2 * i);
		}
		
		printf("%5ld%10.3lf\n",cardnumber,length);
	}
	
	return 0;
}
