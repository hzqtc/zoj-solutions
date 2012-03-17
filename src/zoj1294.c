#include <stdio.h>

int main()
{
	int par,stroke;
	int index = 1;
	
	while(scanf("%d %d",&par,&stroke) , par != 0)
	{
		printf("Hole #%d\n",index++);

		if(stroke == 1)
		{
			puts("Hole-in-one.\n");
			continue;
		}
		else if(stroke - par > 2)
		{
			puts("Double Bogey.\n");
			continue;
		}

		switch (par - stroke)
		{
			case  0:
				puts("Par.\n");
				break;
			case  1:
				puts("Birdie.\n");
				break;
			case  2:
				puts("Eagle.\n");
				break;
			case  3:
				puts("Double Eagle.\n");
				break;
			case -1:
				puts("Bogey.\n");
				break;
			case -2:
				puts("Double Bogey.\n");
				break;
			default:
				break;
		}
	}
	
	return 0;
}
