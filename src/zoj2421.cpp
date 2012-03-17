#include <iostream>
#include <set>

using namespace std;

int num[500001];

void GenNum()
{
	set<int> disnum;
	num[0] = 0;
	disnum.insert(num[0]);
	for(int i = 1; i <= 500000; i++)
	{
		num[i] = num[i - 1] - i;
		if(num[i] <= 0 || disnum.find(num[i]) != disnum.end())
			num[i] = num[i - 1] + i;
		disnum.insert(num[i]);
	}
}

int main()
{
	GenNum();
	int i;
	while(cin >> i, i >= 0)
		cout << num[i] << endl;

	return 0;
}

