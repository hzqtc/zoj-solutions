#include <iostream>

using namespace std;

#define MAX 100

char text[MAX];

struct keyletter
{
	int oldindex;
	int newindex;
	char c;
}key[MAX];

int main()
{
	void rotate(int k);

	int k1,k2,k3;

	while(cin>>k1>>k2>>k3 , (k1 | k2 | k3) != 0)
	{
		cin>>text;

		rotate(k1);
		rotate(k2);
		rotate(k3);

		cout<<text<<endl;
	}

	return 0;
}

void rotate(int k)
{
	int keycount,i;
	static int j = 1;

	keycount = i = 0;

	switch(j)
	{
		case 1:
			while(text[i] != '\0')
			{			
				if(text[i] >= 'a' && text[i] <= 'i')
				{
					key[keycount].oldindex = i;
					key[keycount].c = text[i];
					keycount++;
				}
				i++;
			}
			break;
		case 2:
			while(text[i] != '\0')
			{			
				if(text[i] >= 'j' && text[i] <= 'r')
				{
					key[keycount].oldindex = i;
					key[keycount].c = text[i];
					keycount++;
				}
				i++;
			}
			break;
		case 3:
			while(text[i] != '\0')
			{			
				if((text[i] >= 's' && text[i] <= 'z') || text[i] == '_')
				{
					key[keycount].oldindex = i;
					key[keycount].c = text[i];
					keycount++;
				}
				i++;
			}
			break;
		default:
			break;
	}

	for(i=0;i<keycount;i++)
	{
		int tempindex;
		tempindex = i + k;
		while(tempindex >= keycount)
			tempindex -= keycount;
		key[i].newindex = key[tempindex].oldindex;
	}
	for(i=0;i<keycount;i++)
	{
		text[key[i].newindex] = key[i].c;
	}

	if(j == 3)
		j = 1;
	else
		j++;
}
