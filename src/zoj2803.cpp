#include <iostream>

using namespace std;

const int east  = 0;
const int north = 1;
const int west  = 2;
const int south = 3;

struct R
{
	int x,y;
	int index;
	int d;
};

enum result
{
	failed,
	succeed
};

int robotcount;
const int MAX = 100;
R robot[MAX];
int x_max,y_max;

result move(R* moverobot,int step);

int main()
{
	int casecount;
	int inscount;
	int i;
	
	cin >> casecount;
	while(casecount--)
	{
		cin >> x_max >> y_max;
		cin >> robotcount >> inscount;
		
		for(i=0;i<robotcount;i++)
		{
			char dir;
			cin >> robot[i].x >> robot[i].y >> dir;
			switch(dir)
			{
			case 'E':
				robot[i].d = east;	break;
			case 'W':
				robot[i].d = west;	break;
			case 'N':
				robot[i].d = north;	break;
			case 'S':
				robot[i].d = south; break;
			}
			robot[i].index = i + 1;
		}
		
		int r_index,repeat;
		char type;
		for(i=0;i<inscount;i++)
		{
			
			cin >> r_index >> type >> repeat;
			r_index--;
			
			if(type == 'L')
			{
				repeat %= 4;
				while(repeat--)
				{
					robot[r_index].d++;
					robot[r_index].d %= 4;
				}
			}
			else if(type == 'R')
			{
				repeat %= 4;
				while(repeat--)
				{
					if(robot[r_index].d == 0)
						robot[r_index].d = south;
					else
						robot[r_index].d--;
				}
			}
			else if(type == 'F')
			{
				if(move(&robot[r_index],repeat) == failed)
					break;
			}
		}
		if(i == inscount)
			cout << "OK" << endl;
		else
		{
			i++;
			for(;i<inscount;i++)//read the left data
				cin >> r_index >> type >> repeat;
		}
	}
	
	return 0;
}

result move(R* moverobot,int step)
{
	while(step--)
	{
		switch(moverobot->d)
		{
		case east:
			moverobot->x++;	break;
		case west:
			moverobot->x--;	break;
		case north:
			moverobot->y++;	break;
		case south:
			moverobot->y--;	break;
		}
		
		if(moverobot->x < 1 || moverobot->x > x_max || moverobot->y < 1 || moverobot->y > y_max)
		{
			cout << "Robot " << moverobot->index << " crashes into the wall" << endl;
			return failed;
		}
		else
		{
			for(int i = 0;i<robotcount;i++)
			{
				if(i + 1 != moverobot->index && robot[i].x == moverobot->x && robot[i].y == moverobot->y)
				{
					cout << "Robot " << moverobot->index << " crashes into robot " << i + 1 << endl;
					return failed;
				}
			}
		}
	}
	
	return succeed;
}
