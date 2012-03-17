#include <iostream>
#include <string>

using namespace std;

struct item
{
	string name;
	int pos;
};

int main()
{
	int casecount;
	int itemcount,opecount;
	const int MAX = 20;
	item seq[MAX];
	
	cin >> casecount;
	while(casecount--)
	{
		cin >> itemcount >> opecount;
		int i;
		for(i=0;i<itemcount;i++)
		{
			cin >> seq[i].name;
			seq[i].pos = -1;
		}
		for(i=0;i<opecount;i++)
		{
			int from,to;
			cin >> from >> to;
			seq[from - 1].pos = to;
		}

		bool first = true;
		for(int p = 1;p<=itemcount;p++)
		{
			for(i=0;i<itemcount;i++)
			{
				if(seq[i].pos == p)
				{
					if(first == true)
					{
						cout << seq[i].name;
						first = false;
					}
					else
						cout << ' ' << seq[i].name;
					break;
				}
			}
			if(i == itemcount)//没有找到pos是p的item，则输出第一个pos是－1的项目
			{
				for(int j = 0;j<itemcount;j++)
				{
					if(seq[j].pos == -1)
					{
						if(first == true)
						{
							cout << seq[j].name;
							first = false;
						}
						else
							cout << ' ' << seq[j].name;
						seq[j].pos = p;
						break;
					}
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}

