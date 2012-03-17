#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Point
{
	int x, y, z;
	bool dead;
	Point(): x(0), y(0), z(0), dead(false) {}
	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		dead = false;
	}
};

void ReadPointVector(const string& line, vector<Point>& pv, int d)
{
	istringstream linestream(line);
	int x, y, z;
	char c;
	while(linestream >> x >> c >> y >> c >> z)
	{
		if(z > d)
			z = d;
		pv.push_back(Point(x, y, z));
	}
}

int distance(vector<Point>::iterator a, vector<Point>::iterator b)
{
	return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z);
}

int main()
{
	string line;
	while(getline(cin, line), line != "ENDOFINPUT")
	{
		int l, w, d;

		vector<Point> fish;
		vector<Point> dynamite;

		int cnt = 0;

		istringstream linestream(line.substr(5, line.length() - 5));	// "START ..."
		linestream >> l >> w >> d;
		
		getline(cin, line);
		ReadPointVector(line, dynamite, d);
		getline(cin, line);
		ReadPointVector(line, fish, d);

		getline(cin, line);		// "END"

		for(vector<Point>::iterator iterd = dynamite.begin(); iterd != dynamite.end(); iterd++)
		{
			for(vector<Point>::iterator iterf = fish.begin(); iterf != fish.end(); iterf++)
			{
				if(iterf->dead == false && distance(iterd, iterf) <= 1)
				{
					iterf->dead = true;
					cnt++;
				}
			}
		}
		if(cnt == 0)
			cout << "None of dem fish blowed up!" << endl;
		else
			cout << "AIEE, I got " << cnt << " fish, me!" << endl;
	}

	return 0;
}

