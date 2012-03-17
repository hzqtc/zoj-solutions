#include <cstdio>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct Player
{
	Player(): name(""), score(0), finishHole(0) {}
	Player(const string& s): name(s), score(0), finishHole(0) {}

	double GetAverageScore() const
	{
		return (double)score / finishHole;
	}

	string name;
	int score;
	int finishHole;

	const Player& operator=(const Player& p)
	{
		this->name = p.name;
		this->score = p.score;
		this->finishHole = p.finishHole;

		return *this;
	}

	bool operator<(const Player& cmp) const
	{
		if(this->score != cmp.score)
			return this->score < cmp.score;
		else if(this->GetAverageScore() != cmp.GetAverageScore())
			return this->GetAverageScore() < cmp.GetAverageScore();
		else
			return this->name < cmp.name;
	}
};

void ShowRank(const map<string, Player>& m, int holeCount);

int main()
{
	int caseCount;

	scanf("%d", &caseCount);
	for(int caseIndex = 1; caseIndex <= caseCount; caseIndex++)
	{
		int holeCount;
		int holePar[18];			// par of each hole
		map<string, Player> p;		// all players
		scanf("%d", &holeCount);
		for(int i = 0; i < holeCount; i++)
			scanf("%d", holePar + i);
		printf("Tournament %d\n", caseIndex);
		char tmp[20];
		string s;
		while(scanf("%s", tmp), (s = string(tmp)) != "EndOfTournament")
		{
			if(s == "ShowRank")
				ShowRank(p, holeCount);
			else
			{
				int n;
				scanf("%d", &n);
				if(p.find(s) == p.end())
					p.insert(make_pair(s, Player(s)));
				p[s].score += n - holePar[p[s].finishHole++];
			}
		}
	}

	return 0;
}

void ShowRank(const map<string, Player>& m, int holeCount)
{
	Player p[100];
	int cnt = 0;
	for(map<string, Player>::const_iterator iter = m.begin(); iter != m.end(); iter++)
		p[cnt++] = iter->second;
	sort(p, p + cnt);
	puts("Place  Name        Score  Holes");
	for(int i = 0; i < cnt; i++)
	{
		int place = i + 1;
		int lastPlace;
		if(i > 0 && p[i].score == p[i - 1].score)
			place = lastPlace;
		lastPlace = place;

		printf("%5d  %-10s  ", place, p[i].name.c_str());

		if(p[i].score == 0)
			printf("%5d  ", 0);
		else
			printf("%+5d  ",  p[i].score);
		
		if(p[i].finishHole == holeCount)
			printf("%5c\n", 'F');
		else
			printf("%5d\n", p[i].finishHole);
	}
	putchar('\n');
}
