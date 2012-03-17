#include <iostream>
#include <map>

using namespace std;

inline int SQ(int x)
{
	return x * x;
}

int main()
{
	int casecount,caseindex = 1;
	int ax,ay,bx,by,cx,cy,dx,dy;
	map<int,int> dis;
	
	cin >> casecount;
	while(casecount--)
	{
		dis.clear();
		
		cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
		dis[SQ(ax - bx) + SQ(ay - by)]++;
		dis[SQ(ax - cx) + SQ(ay - cy)]++;
		dis[SQ(ax - dx) + SQ(ay - dy)]++;
		dis[SQ(bx - cx) + SQ(by - cy)]++;
		dis[SQ(bx - dx) + SQ(by - dy)]++;
		dis[SQ(cx - dx) + SQ(cy - dy)]++;
	
		if(caseindex > 1)
			cout << endl;
		cout << "Case " << caseindex++ << ':' << endl;
		if(dis.size() == 2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}

