#include <iostream>

using namespace std;

int main()
{
	int match,competer;
	int mod;

	while(cin>>competer , competer != 0)
	{
		match = 0;
		while(competer > 1)
		{
			if(competer <= 3)
			{
				match++;
				break;
			}
			else
			{
				mod = competer % 3;
				match += (competer /= 3);
				competer += mod;
			}
		}
		cout<<match<<endl;
	}

	return 0;
}