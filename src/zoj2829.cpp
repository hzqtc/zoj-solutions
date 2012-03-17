#include <iostream>

using namespace std;

int main()
{
	const int MAX = 100000;

	int bnum[MAX],count = 0;
	int num = 3;

	while(count <= MAX)
	{
		if(num % 3 == 0 || num % 5 == 0)
			bnum[count++] = num;

		num ++;
	}

	int index;
	while(cin>>index)
	{
		cout<<bnum[index - 1]<<endl;
	}

	return 0;
}