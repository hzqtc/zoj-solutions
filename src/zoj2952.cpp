#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const long long POW_MAX = 2147483648;
long long llpower(long long a, long long b);

int main()
{
	vector<long long> v;
	long long i, j;
	for(i = 2; i < 46341; i++)
	{
		j = 2;
		long long tmp;
		while((tmp = llpower(i, j++)) < POW_MAX)
			v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(vector<long long>::iterator iter = v.begin(); iter != v.end(); iter++)
		printf("%lld\n", *iter);
	return 0;
}

long long llpower(long long a, long long b)
{
	long long re = a;
	while(--b)
	{
		re *= a;
		if(re >= POW_MAX)
			break;
	}
	return re;
}
