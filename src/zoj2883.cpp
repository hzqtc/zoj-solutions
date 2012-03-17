#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int num;
	int numCount;
	int caseCount;
	vector<int> cost;
	int discount;

	scanf("%d", &caseCount);
	while(caseCount--)
	{
		scanf("%d", &numCount);
		cost.clear();
		discount = 0;
		while(numCount--)
		{
			scanf("%d", &num);
			cost.push_back(num);
		}
		sort(cost.begin(), cost.end());
		for(int i = cost.size() - 3; i >= 0; i -= 3)
			discount += cost[i];
		printf("%d\n", discount);
	}

	return 0;
}
