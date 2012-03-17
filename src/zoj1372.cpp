#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 64;
const int INFINITE = 128;

struct Connection
{
	int from, to;
	int weight;
	Connection(int from, int to, int weight)
	{
		this->from = from;
		this->to = to;
		this->weight = weight;
	}
	Connection()
	{
		this->from = this->to = 0;
		this->weight = INFINITE;
	}
};

bool operator<(const Connection& a, const Connection& b)
{
	return a.weight > b.weight;
}

int main()
{
	int nodeCount, connectCount;
	while(cin >> nodeCount, nodeCount > 0)
	{
		cin >> connectCount;
		priority_queue<Connection> network;
		int graph[MAX_SIZE][MAX_SIZE];
		bool visited[MAX_SIZE];
		for(int i = 0; i < MAX_SIZE; i++)
		{
			for(int j = 0; j < MAX_SIZE; j++)
				graph[i][j] = INFINITE;
			visited[i] = false;
		}

		Connection min;
		while(connectCount--)
		{
			int from, to, weight;
			cin >> from >> to >> weight;
			if(weight < graph[from][to])
			{
				graph[from][to] = graph[to][from] = weight;
				if(weight < min.weight)
					min = Connection(from, to, weight);
			}
		}

		for(int i = 1;i <= nodeCount; i++)
		{
			if(graph[min.from][i] < INFINITE)
				network.push(Connection(min.from, i, graph[min.from][i]));
		}
		visited[min.from] = true;
		int totalCost = 0;
		int knownNode = 1;

		while(knownNode < nodeCount)
		{
			Connection c = network.top();
			network.pop();
			if(visited[c.to] == false)
			{
				totalCost += c.weight;
				visited[c.to] = true;
				for(int i = 1;i <= nodeCount; i++)
				{
					if(graph[c.to][i] < INFINITE)
						network.push(Connection(c.to, i, graph[c.to][i]));
				}
				knownNode++;
			}
		}

		cout << totalCost << endl;
	}
	return 0;
}
