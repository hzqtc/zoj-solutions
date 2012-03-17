#include <iostream>

using namespace std;

int main()
{
	int count,i;
	int timelast,time;
	int speed,distance;
	
	while(cin>>count , count != -1)
	{
		timelast = distance = 0;
		for(i=0;i<count;i++)
		{
			cin>>speed>>time;
			distance += (time - timelast) * speed;
			timelast = time;
		}
		cout<<distance<<" miles"<<endl;
	}
	
	return 0;
}
