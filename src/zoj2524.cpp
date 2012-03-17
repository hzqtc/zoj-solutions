#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int cmp_name(const void* a,const void* b);
int cmp_goal(const void* a,const void* b);
int cmp_points(const void* a,const void* b);

class team
{
public:
	team()
	{
		name = "";
		win = draw = lose = points = goal = 0;
	}
	string name;
	int win,draw,lose;
	int points,goal;
};

int main()
{
	const int MAX = 10000;
	int matchcount;
	int index = 0;

	while(scanf("%d",&matchcount) != EOF)
	{
		if(index++ > 0)
			putchar('\n');
		int i;
		map<string,team> record;
		for(i=0;i<matchcount;i++)
		{
			char t1[50],t2[50];
			int g1,g2;
			scanf("%s %d:%d %s",t1,&g1,&g2,t2);
			string st1(t1);
			string st2(t2);
			record[st1].goal += (g1 - g2);
			record[st2].goal += (g2 - g1);
			if(g1 > g2)
			{
				record[st1].win++;
				record[st1].points += 3;
				record[st2].lose++;
			}
			else if(g1 < g2)
			{
				record[st1].lose++;
				record[st2].win++;
				record[st2].points += 3;
			}
			else
			{
				record[st1].draw++;
				record[st1].points++;
				record[st2].draw++;
				record[st2].points++;
			}
		}
		team teamlist[MAX];
		map<string,team>::iterator iter = record.begin();
		for(i=0;i<record.size();i++)
		{
			teamlist[i] = iter->second;
			teamlist[i].name = iter->first;
			iter++;
		}
		qsort(teamlist,record.size(),sizeof(team),cmp_name);
		qsort(teamlist,record.size(),sizeof(team),cmp_goal);
		qsort(teamlist,record.size(),sizeof(team),cmp_points);
		for(i=0;i<record.size();i++)
			printf("%d %s %d %d %d %d %d\n",i + 1,teamlist[i].name.c_str(),teamlist[i].win,teamlist[i].draw,teamlist[i].lose,teamlist[i].points,teamlist[i].goal);
	}
	
	return 0;
}

int cmp_name(const void* a,const void* b)
{
	if(((team*)a)->name == ((team*)b)->name)
		return 0;
	else if(((team*)a)->name > ((team*)b)->name)
		return 1;
	else
		return -1;
}

int cmp_goal(const void* a,const void* b)
{
	return ((team*)b)->goal - ((team*)a)->goal;
}

int cmp_points(const void* a,const void* b)
{
	return ((team*)b)->points - ((team*)a)->points;
}

