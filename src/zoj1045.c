#include <stdio.h>

#define eps 0.01

#define notzero(x) ((x) < -eps || (x) > eps)

int main()
{
	int mincount;
	double myl,length;

	while(1)
	{
		mincount=1;
		myl=0.0;

		scanf("%lf",&length);
		
		if(notzero(length))/*²»µÈÓÚ0*/
		{
			while(myl < length)
			{
				myl+=(double)(1 / (double)(++mincount));
			}

			printf("%d card(s)\n",--mincount);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}
