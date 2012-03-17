/*Time Limit Exceeded*/
#include <stdio.h>

#define MAX	500

int main()
{
	int casecount,index,querycount,r1,c1,r2,c2;
	int row,column,x,y,i;
	int matrix[MAX][MAX];
	
	scanf("%d",&casecount);
	for(index=0;index<casecount;index++)
	{
		scanf("%d %d",&row,&column);
		for(x=0;x<row;x++)
		{
			for (y=0;y<column;y++)
			{
				scanf("%d",&matrix[x][y]);
				matrix[x][y] *= matrix[x][y];
				if(x == 0)
				{
					if(y > 0)
						matrix[x][y] += matrix[x][y - 1];
				}
				else if( y == 0)
				{
					matrix[x][y] += matrix[x - 1][y];
				}
				else
				{
					matrix[x][y] += matrix[x][y - 1] + matrix[x - 1][y] - matrix[x - 1][y - 1];
				}
			}
		}

		printf("Case %d:\n",index + 1);
		scanf("%d",&querycount);
		for(i=0;i<querycount;i++)
		{
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
			r1--;
			r2--;
			c1--;
			c2--;
			if(r1 > 0 && c1 > 0)
				printf("%d\n",matrix[r2][c2] + matrix[r1 - 1][c1 - 1] - matrix[r2][c1 - 1] - matrix[r1 - 1][c2]);
			else if(r1 > 0)
				printf("%d\n",matrix[r2][c2] - matrix[r1 - 1][c2]);
			else if(c1 > 0)
				printf("%d\n",matrix[r2][c2] - matrix[r2][c1 - 1]);
			else
				printf("%d\n",matrix[r2][c2]);
		}
	}
	
	return 0;
}
