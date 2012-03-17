/*Runtime Error SIGFPE  --- Divided by 0*/
#include <stdio.h>
#include <math.h>

int main()
{
	int carbon,decay;
	int year;
	int index = 0;
	
	void format(int * year);
	
	while(scanf("%d %d",&carbon,&decay) , carbon * decay != 0)
	{
		year = (int)(log(810 / ((double)decay / (double)carbon)) / log(2) * 5730);

		format(&year);

		printf("Sample #%d\nThe approximate age is %d years.\n\n",++index,year);
	}
	
	return 0;
}

void format(int * year)
{
	if(*year < 10000)
	{
		if(*year % 100 >= 50)
			*year += (100 - *year % 100);
		else
			*year -= *year % 100;
	}
	else if(*year > 10000)
	{
		if(*year % 1000 >= 500)
			*year += (1000 - *year %1000);
		else
			*year -= *year % 1000;
	}
}