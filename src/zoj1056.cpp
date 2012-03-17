#include <iostream>
#include <string>

using namespace std;

enum dir{east,west,north,south};
enum state{ok,off,into};

const int WORM_LENGTH = 20;

class point
{
public:
	int x,y;
};

class cls_worm
{
private:
	point coordinate[WORM_LENGTH];
	state checkvild();

public:
	state move(dir d);
	cls_worm();
	void init(void);
}worm;


int main()
{
	int movestep;
	string movedir;
	int i;
	state re;
	dir temp;

	while(cin>>movestep , movestep != 0)
	{
		cin>>movedir;
		worm.init();
		for(i=0;i<movestep;i++)
		{
			if(movedir[i] == 'E')
				temp = east;
			else if(movedir[i] == 'W')
				temp = west;
			else if(movedir[i] == 'N')
				temp = north;
			else if(movedir[i] == 'S')
				temp = south;

			re = worm.move(temp);
			if(re == into)
			{
				cout<<"The worm ran into itself on move "<<i + 1<<"."<<endl;
				break;
			}
			else if(re == off)
			{
				cout<<"The worm ran off the board on move "<<i + 1<<"."<<endl;
				break;
			}
		}
		if(i >= movestep)
			cout<<"The worm successfully made all "<<movedir.length()<<" moves."<<endl;
	}

	return 0;
}

cls_worm::cls_worm()
{
	init();
}

void cls_worm::init(void)
{
	for(int i = 0;i<WORM_LENGTH;i++)/*从头到尾是index从0开始到WORM_LENGTH - 1*/
	{
		this->coordinate[i].x = 25;
		this->coordinate[i].y = 11 + i;
	}

}
state cls_worm::move(dir d)
{
	int index;

	switch(d)
	{
	case east:
		for(index = 0;index<WORM_LENGTH - 1;index++)
		{
			this->coordinate[index].x = this->coordinate[index + 1].x;
			this->coordinate[index].y = this->coordinate[index + 1].y;
		}
		this->coordinate[WORM_LENGTH - 1].y++;
		break;
	case west:
		for(index = 0;index<WORM_LENGTH - 1;index++)
		{
			this->coordinate[index].x = this->coordinate[index + 1].x;
			this->coordinate[index].y = this->coordinate[index + 1].y;
		}
		this->coordinate[WORM_LENGTH - 1].y--;
		break;
	case north:
		for(index = 0;index<WORM_LENGTH - 1;index++)
		{
			this->coordinate[index].x = this->coordinate[index + 1].x;
			this->coordinate[index].y = this->coordinate[index + 1].y;
		}
		this->coordinate[WORM_LENGTH - 1].x--;
		break;
	case south:
		for(index = 0;index<WORM_LENGTH - 1;index++)
		{
			this->coordinate[index].x = this->coordinate[index + 1].x;
			this->coordinate[index].y = this->coordinate[index + 1].y;
		}
		this->coordinate[WORM_LENGTH - 1].x++;
		break;
	default:
		break;
	}

	return this->checkvild();
}

state cls_worm::checkvild()
{
	int index;

	for(index = 0;index<WORM_LENGTH;index++)
	{
		if(this->coordinate[index].x > 50 || this->coordinate[index].x < 1 || this->coordinate[index].y > 50 || this->coordinate[index].y < 1)
			return off;
	}

	for(index = 0;index<WORM_LENGTH-1;index++)
	{
		if(this->coordinate[WORM_LENGTH - 1].x == this->coordinate[index].x && this->coordinate[WORM_LENGTH - 1].y == this->coordinate[index].y)
			return into;
	}

	return ok;
}