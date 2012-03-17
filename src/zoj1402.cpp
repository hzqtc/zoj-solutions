#include <iostream>

using namespace std;

int main()
{
	const int MAX = 32;

	class server
	{
	public:
		int index;//当前所处客人的编号
		int serve;//送出去的肉丸数
	}ella,sam;

	int guestcount,guestorder[MAX],totalorder;
	int i;

	while(cin>>guestcount , guestcount != 0)
	{
		totalorder = 0;
		for(i=0;i<guestcount;i++)
		{
			cin>>guestorder[i];
			totalorder += guestorder[i];
		}
		if(totalorder % 2)
			cout<<"No equal partitioning."<<endl;
		else
		{
			ella.index = guestcount;
			sam.index = 1;
			ella.serve = sam.serve = 0;
			while(ella.serve < totalorder / 2)
			{
				ella.serve += guestorder[--ella.index];
			}
			ella.index++;
			if(ella.serve == totalorder / 2)
			{
				sam.index = ella.index - 1;
				cout<<"Sam stops at position "<<sam.index<<" and Ella stops at position "<<ella.index<<"."<<endl; 
			}
			else
				cout<<"No equal partitioning."<<endl;
		}
	}

	return 0;
}
