#include <iostream>

using namespace std;

int main()
{
	int child,round;
	const int MAX = 1000;
	int candy[MAX],add[MAX];
	int i;

	while(cin>>child , child != 0)
	{
		for(i=0;i<child;i++)
		{
			cin>>candy[i];
		}
		round = 1;
		while(1)
		{
			add[child - 1] = (candy[0] /= 2);
			for(i=1;i<child;i++)
			{
				add[i - 1] = (candy[i] /= 2);
			}
			for(i=0;i<child;i++)
			{
				candy[i] += add[i];
				if(candy[i] % 2)
					candy[i]++;
			}
			for(i=0;i<child-1;i++)
			{
				if(candy[i] != candy[i + 1])
					break;
			}
			if(i == child - 1)
				break;

			round++;
		}
		cout<<round<<' '<<candy[0]<<endl;
	}

	return 0;
}