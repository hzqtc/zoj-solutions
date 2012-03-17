#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000;
const int LEN = 30;

struct dic
{
	char name[LEN];
	int value;
}d[MAX];

int main()
{
	int diccount,i,descount;
	int value;
	char word[LEN];

	cin>>diccount>>descount;
	for(i=0;i<diccount;i++)
	{
		cin>>d[i].name>>d[i].value;
	}

	while(descount--)
	{
		value = 0;
		while(cin>>word , strcmp(word,"."))
		{
			for(int j = 0;j<diccount;j++)
			{
				if(strcmp(word,d[j].name) == 0)
				{
					value += d[j].value;
					break;
				}
			}
		}
		cout<<value<<endl;
	}

	return 0;
}