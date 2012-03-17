#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX = 16;
struct dieter
{
	string name;
	int dietday;
	int weight;
}d[MAX];

int cmp(const void * a,const void * b);

int main()
{
	int dcount;
	string cmd;
	int caseindex = 0;

	while(cin>>cmd)
	{
		if(cmd == "START")
		{
			dcount = 0;
			if(caseindex++)
				cout<<endl;
		}
		else if(cmd == "END")
		{
			qsort(d,dcount,sizeof(dieter),cmp);
			while(dcount--)
			{
				cout<<d[dcount].name<<endl;
			}
		}
		else
		{
			d[dcount].name = cmd;
			cin>>d[dcount].dietday>>d[dcount].weight;
			dcount++;
		}
	}

	return 0;
}

int cmp(const void * a,const void * b)
{
	dieter * p1 = (dieter *)a,* p2 = (dieter *)b;
	int w1 = p1->weight - p1->dietday;
	int w2 = p2->weight - p2->dietday;

	if(w1 < 1)
		w1 = 1;
	if(w2 < 1)
		w2 = 1;

	return w1 - w2;
}