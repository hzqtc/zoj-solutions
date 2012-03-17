#include <cstdio>

using namespace std;

int main()
{
	const int MAX = 100;
	
	int size;
	int num[MAX][MAX];
	int sum_column[MAX],sum_row[MAX];
	int odd_column,odd_row;
	int bit_row,bit_column;
	int i,j;
	
	while(scanf("%d",&size) , size != 0)
	{
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
				scanf("%d",&num[i][j]);
		}
		odd_column = odd_row = 0;
	
		for(i=0;i<size;i++)
		{
			sum_row[i] = 0;
			for(j=0;j<size;j++)
				sum_row[i] += num[i][j];
			if(sum_row[i] % 2)
			{
				odd_row++;
				bit_row = i;
			}
		}
		for(j=0;j<size;j++)
		{
			sum_column[j] = 0;
			for(i=0;i<size;i++)
				sum_column[j] += num[i][j];
			if(sum_column[j] % 2)
			{
				odd_column++;
				bit_column = j;
			}
		}
		if(odd_row == 0 && odd_column == 0)
			puts("OK");
		else if(odd_row == 1 && odd_column == 1)
			printf("Change bit (%d,%d)\n",bit_row + 1,bit_column + 1);
		else
			puts("Corrupt");
	}
	
	return 0;
}

