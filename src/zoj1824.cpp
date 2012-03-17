#include <iostream>

using namespace std;

int main()
{
	int row,col;
	struct r
	{
		int x,y;
		char dir;
	}robot;
	char cmd;
	int i,j;
	const int MAX = 64;
	char map[MAX][MAX];
	
	while(cin>>row>>col)
	{
		getchar();
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				map[i][j] = getchar();
			}
			getchar();
		}
		cin>>robot.x>>robot.y;
		robot.x--;
		robot.y--;
		robot.dir = 'N';
		getchar();
		while((cmd = getchar()) != 'Q')
		{
			switch(cmd)
			{
				case 'R':
					switch(robot.dir)
					{
						case 'N':
							robot.dir = 'E';
							break;
						case 'S':
							robot.dir = 'W';
							break;
						case 'E':
							robot.dir = 'S';
							break;
						case 'W':
							robot.dir = 'N';
							break;
						default :
							break;
					}
					break;
				case 'L':
					switch(robot.dir)
					{
						case 'N':
							robot.dir = 'W';
							break;
						case 'S':
							robot.dir = 'E';
							break;
						case 'E':
							robot.dir = 'N';
							break;
						case 'W':
							robot.dir = 'S';
							break;
						default :
							break;
					}
					break;
				case 'F':
					switch(robot.dir)
					{
						case 'N':
							if(map[robot.x - 1][robot.y] != '*')
								robot.x--;
							break;
						case 'S':
							if(map[robot.x + 1][robot.y] != '*')
								robot.x++;
							break;
						case 'E':
							if(map[robot.x][robot.y + 1] != '*')
								robot.y++;
							break;
						case 'W':
							if(map[robot.x][robot.y - 1] != '*')
								robot.y--;
							break;
						default :
							break;
					}
					break;
				default :
					break;
			}
			//if(cmd != ' ' && cmd != '\n')
			//	cout<<cmd<<' '<<robot.x + 1<<' '<<robot.y + 1<<' '<<robot.dir<<endl;
		}
		cout<<robot.x + 1<<' '<<robot.y + 1<<' '<<robot.dir<<endl;
	}
	
	return 0;
}

