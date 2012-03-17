#include <cstdio>

using namespace std;

const int maxpeople = 100001;
int friendgroup[maxpeople];

int find(int element);
int findcount(int element);

int main()
{
	int peoplecount;
	int linecount;
	int casecount = 1;
	int i;

	while(scanf("%d %d", &peoplecount, &linecount) != EOF)
	{
		if(casecount > 1)			// add a blank line between each case
			putchar('\n');
		printf("Case %d:\n", casecount++);
		
		for(i=1;i<=peoplecount;i++)
			friendgroup[i] = -1;	// size of each set is initialized to 1
			
		while(linecount--)
		{
			char cmd;
			int p1, p2;
			do
			{
				scanf("%c", &cmd);
			}
			while(cmd == '\n');
			if(cmd == 'M')
			{
				scanf("%d %d", &p1, &p2);
				int root1, root2;
				root1 = find(p1);
				root2 = find(p2);
				if(root1 != root2)
				{
					if(friendgroup[root1] < friendgroup[root2])
					{
						friendgroup[root1] += friendgroup[root2];
						friendgroup[root2] = root1;
					}
					else
					{
						friendgroup[root2] += friendgroup[root1];
						friendgroup[root1] = root2;
					}
				}
			}
			else if(cmd == 'Q')
			{
				scanf("%d", &p1);
				printf("%d\n", findcount(p1));
			}
		}
	}
	
	return 0;
}

int find(int element)
{
	if(friendgroup[element] <= 0)
		return element;
	else
		return friendgroup[element] = find(friendgroup[element]);
}

int findcount(int element)
{
	while(friendgroup[element] > 0)
		element = friendgroup[element];
	return -friendgroup[element];
}

/*
3 5
M 1 2
Q 1
Q 3
M 2 3
Q 2
5 10
M 3 2
Q 4
M 1 2
Q 4
M 3 2
Q 1
M 3 1
Q 5
M 4 2
Q 4
*/
