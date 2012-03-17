#include <iostream>

using namespace std;

struct loc
{
	int r,c;
};

int main()
{
	int row,col;
	int i,j;
	loc robot;
	const int MAX = 16;
	char cmd[MAX][MAX];
	loc step[1000];
	int stepcount,sindex;
	bool bre;

	while(cin>>row>>col>>robot.c , row != 0)
	{
		robot.r = 0;
		robot.c--;
		step[0].c = robot.c;
		step[0].r = robot.r;
		stepcount = 1;
		bre = false;

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cin>>cmd[i][j];
			}
		}
		while(1)
		{
			if(robot.r < 0 || robot.r >= row || robot.c < 0 || robot.c >= col)
			{
				cout<<stepcount - 1<<" step(s) to exit"<<endl;
				break;
			}
			switch(cmd[robot.r][robot.c])
			{
			case 'E':
				robot.c++;
				break;
			case 'W':
				robot.c--;
				break;
			case 'S':
				robot.r++;
				break;
			case 'N':
				robot.r--;
				break;
			default :
				break;
			}
			for(sindex=0;sindex<stepcount;sindex++)
			{
				if(step[sindex].r == robot.r && step[sindex].c == robot.c)
				{
					cout<<sindex<<" step(s) before a loop of "<<stepcount - sindex<<" step(s)"<<endl;
					bre = true;
					break;
				}
			}
			if(bre == true)
				break;
			step[stepcount].r = robot.r;
			step[stepcount].c = robot.c;
			stepcount++;
		}
	}

	return 0;
}