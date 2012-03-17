#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int distance;
	int index;
};

int main()
{
	const int MAX = 21;
	int caseIndex = 1;

	int n, i, j;

	while(cin >> n)
	{
		Node node[MAX];
		bool graph[MAX][MAX] = {{false}};
		while(n--)
		{
			cin >> i;
			graph[i][1] = graph[1][i] = true;
		}
		for(j = 2; j <= 19; j++)
		{
			cin >> n;
			while(n--)
			{
				cin >> i;
				graph[i][j] = graph[j][i] = true;
			}
		}
		
		cout << "Test Set #" << caseIndex++ << endl;
		cin >> n;
		while(n--)
		{
			for(i = 0; i < MAX; i++)
			{
				node[i].index = i;
				node[i].distance = 20;
			}
			queue<Node> q;
			int from, to;
			cin >> from >> to;
			node[from].distance = 0;
			q.push(node[from]);
			while(q.empty() == false)
			{
				Node v = q.front();
				q.pop();
				for(i = 1; i < MAX; i++)
				{
					if(graph[v.index][i] == true && node[i].distance > v.distance + 1)
					{
						node[i].distance = v.distance + 1;
						q.push(node[i]);
					}
				}
			}
			cout << from << " to " << to << ": " << node[to].distance << endl;
		}
		cout << endl;
	}

	return 0;
}
