#include <iostream>
#include <map>

using namespace std;

enum state{none,lose,extra};

struct P 
{
	int loc;
	state s;
};

int checkwin(struct P* p,int pcount);

int main()
{
	const int MAX = 1000;
	const int PLAYER = 6;

	int die[MAX],diecount = 0;
	map<int,int> ladder;
	map<int,state> turn;
	P player[PLAYER];
	int playercount;
	int i = 0,j = 0;

	while(cin >> die[diecount] , die[diecount] > 0)
		diecount++;

	while(cin >> playercount , playercount > 0)
	{
		for(i=0;i<playercount;i++)
		{
			player[i].loc = 0;
			player[i].s = none;
		}

		int s,e,t;

		ladder.clear();
		turn.clear();
		while(cin >> s >> e , s > 0 && e > 0)
			ladder[s] = e;
		while(cin >> t , t != 0)
			turn[t < 0 ? -t : t] = (t > 0 ? extra : lose);

		int win;
		i = j = 0;
		while(!(win = checkwin(player,playercount)))
		{
			if(player[j].s == lose)
			{
				player[j].s = none;
				j++;
				continue;
			}
			if(!(player[j].loc >= 95 && player[j].loc + die[i] > 100))
				player[j].loc += die[i];

			map<int,int>::iterator iter1 = ladder.find(player[j].loc);
			map<int,state>::iterator iter2 = turn.find(player[j].loc);

			if(iter1 != ladder.end())
				player[j].loc = iter1->second;
			else if(iter2 != turn.end())
			{
				player[j].s = iter2->second;
				if(player[j].s == extra)
				{
					player[j].s = none;
					j--;
				}
			}

			i++;
			j++;
			j %= playercount;
		}
		cout << win << endl;
	}

	return 0;
}

int checkwin(struct P* p,int pcount)//return 0 if none wins, else return his index + 1
{
	for(int i = 0;i<pcount;i++)
	{
		if(p[i].loc == 100)
			return i + 1;
	}
	return 0;
}