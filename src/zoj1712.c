#include <stdio.h>
#include <math.h>

#define MAXSKEW 100

int main()
{
	int		SkewBin[MAXSKEW];
	int		Bit,Index,Length;
	char	Temp;
	long	DecNum;

	while(1)
	{
		Length = 0;
		while((Temp = getchar()) != '\n')
		{
			SkewBin[Length++] = Temp - '0';
		}

		if(Length == 1 && SkewBin[0] == 0)
		{
			break;
		}
		else
		{
			DecNum = 0;
			for(Index=0;Index<Length;Index++)
			{
				Bit = SkewBin[Index];
				if(Bit != 0)
				{
					DecNum += Bit * (long)(pow(2,Length - Index) - 1);
				}
			}

			printf("%ld\n",DecNum);
		}
	}

	return 0;
}