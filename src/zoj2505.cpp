#include <iostream>

using namespace std;

enum stickstate
{
	parallel,
	normal
};

int main()
{
	int casecount,secondcount;
	const int MAX = 4096;
	int maxlen,len;
	stickstate state[MAX];

	cin >> casecount;
	while(casecount--)
	{
		cin >> secondcount;
		int i;
		for(i=0;i<MAX;i++)
			state[i] = parallel;
		
		maxlen = 0;
		while(secondcount--)
		{
			int stickindex;
			cin >> stickindex;
			stickindex--;
			if(state[stickindex] == parallel)
			{
				state[stickindex] = normal;
				len = 1;
				i = stickindex - 1;
				while(i >= 0 && state[i] == normal)
				{
					len++;
					i--;
				}
				i = stickindex + 1;
				while(i < MAX && state[i] == normal)
				{
					len++;
					i++;
				}
				if(len > maxlen)
					maxlen = len;
			}
			else
				state[stickindex] = parallel;
		}
		cout << maxlen << endl;
	}

	return 0;
}
