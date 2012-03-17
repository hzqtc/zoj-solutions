#include <iostream>

using namespace std;

int main()
{
	int fuel;
	int cubic;
	int temp,shoot;
	int i,j;

	while(cin>>fuel , fuel != 0)
	{
		shoot = temp = 0;
		for(i = 0;(cubic = i * i * i) <= fuel;i++)
		{
			for(j = 0;(temp = j * (j + 1) * (j + 2) / 6 + cubic) <= fuel;j++)
			{
				if(temp > shoot)
					shoot = temp;
			}
		}
		cout<<shoot<<endl;
	}

	return 0;
}