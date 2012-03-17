#include <iostream>
#include <string>

using namespace std;

int main()
{
	int teamcount;
	struct team
	{
		int solved;
		int time;
		string name;
	}winer={0,0,""},temp;
	
	cin>>teamcount;
	while(teamcount--)
	{
		temp.solved = 0;
		temp.time = 0;
		cin>>temp.name;
		int sub,time;
		for(int i = 0;i<4;i++)
		{
			cin>>sub>>time;
			if(time > 0)
			{
				temp.solved++;
				temp.time += (sub - 1) * 20 + time;
			}
		}
		
		if(winer.name == "" || winer.solved < temp.solved)
			winer = temp;
		else if(winer.solved == temp.solved && winer.time > temp.time)
			winer = temp;
	}
	
	cout<<winer.name<<' '<<winer.solved<<' '<<winer.time<<endl;
	
	return 0;
}
