#include <iostream>
#include <string>

using namespace std;

const int MAX = 1024;
class color
{
public:
	string name;
	int count;
}c[MAX];

inline void init(void);

int main()
{
	int n,i,j;
	string temp;
	color * max;

	while(cin>>n , n != 0)
	{
		max = NULL;
		init();
		for(i=0;i<n;i++)
		{
			cin>>temp;
			for(j=0;j<=i;j++)
			{
				if(c[j].name == temp)
				{
					c[j].count++;
					if(max == NULL || max->count < c[j].count)
						max = &c[j];
					break;
				}
				else if(c[j].count == 0)
				{
					c[j].name = temp;
					c[j].count++;
					if(max == NULL || max->count < c[j].count)
						max = &c[j];
					break;
				}
			}
		}
		cout<<max->name<<endl;
	}

	return 0;
}

void init(void)
{
	for(int i = 0;i<MAX;i++)
	{
		c[i].name = "";
		c[i].count = 0;
	}
}