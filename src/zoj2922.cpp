#include <cstdio>

using namespace std;

const int MAX_SIZE = 1000;
int power[MAX_SIZE][MAX_SIZE];
bool exploded[MAX_SIZE][MAX_SIZE];

int explode(int row, int col);

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &power[i][j]);
				exploded[i][j] = false;
			}
		}
		int count = 0;
		for(int j = m - 1; j >= 0; j--)
			for(int i = n - 1; i >= 0; i--)
				count += explode(i, j);
		printf("%d\n", count);
	}

	return 0;
}

int explode(int row, int col)
{
	if(power[row][col] == 0)
		return 0;
	else
	{
		for(int i = row - 1; i >= 0; i--)
			exploded[i][col] = true;
		for(int i = col - 1; i >= 0 && col - i <= power[row][col]; i--)
			exploded[row][i] = true;
		if(exploded[row][col] == true)
			return 0;
		else
		{
			exploded[row][col] = true;
			return 1;
		}
	}
}

