#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct GraphNode
{
	int distance;
	int prenode;
	int index;
};

class DirectedGraph
{
public:
	static const int max_size = 21;

	DirectedGraph(int s): size(s)
	{
		for(int i = 1; i <= size; i++)
		{
			for(int j = 0; j <= size; j++)
				originalPath[i][j] = -1;
		}
		tag = -1;
	}

	void ConnectNodes(int from, int to, int pathWeight)			// add a path between two nodes
	{
		originalPath[from][to] = pathWeight;
	}

	int GetShortestPathLength(int from, int to)					// return the shortest path between two nodes
	{
		if(tag != from)
			GenShortestPathForNode(from);
		return vertex[to].distance;
	}

	vector<int> GetShortestPath(int from, int to)				// return a vector contain all node on the shortest path
	{
		if(tag != from)
			GenShortestPathForNode(from);
		GraphNode v = vertex[to];
		stack<int> path;
		while(v.index != from)
		{
			path.push(v.index);
			v = vertex[v.prenode];
		}
		path.push(v.index);
		vector<int> pathOrder;
		while(path.empty() == false)
		{
			pathOrder.push_back(path.top());
			path.pop();
		}
		return pathOrder;
	}

	void GenShortestPathForNode(int node)		// get all shortest path from one node to others, Dijkstra's algorithm
	{
		tag = node;
		// initialization
		for(int i = 1; i <= size; i++)
		{
			vertex[i].distance = vertex[i].prenode = -1;
			vertex[i].index = i;
		}

		// use a queue
		queue<GraphNode> q;
		vertex[node].distance = 0;				// 0 distance to itself
		q.push(vertex[node]);
		while(q.empty() == false)
		{
			GraphNode v = q.front();
			q.pop();
			for(int i = 1; i <= size; i++)	// all adjacent nodes of v
			{
				if(originalPath[v.index][i] != -1)
				{
					if(vertex[i].distance == -1 || (v.distance + originalPath[v.index][i] < vertex[i].distance))
					{
						vertex[i].prenode = v.index;
						vertex[i].distance = v.distance + originalPath[v.index][i];
						q.push(vertex[i]);
					}
				}
			}
		}
	}
private:
	int originalPath[max_size][max_size];
	GraphNode vertex[max_size];
	int tag;									// tag to record which node is GenShortestPath for
	int size;
};

struct Path
{
	int from;
	int to;
	int distance;
	vector<int> nodes;
};

bool PathCmp(const Path& a, const Path& b)
{
	return a.distance < b.distance;
}

int main()
{
	int caseCount;
	
	cin >> caseCount;
	while(caseCount--)
	{
		int n, p;
		cin >> n;
		DirectedGraph g(n);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cin >> p;
				g.ConnectNodes(i, j, p);
			}
		}

		string line;
		getline(cin, line);
		getline(cin, line);
		istringstream lineStream(line);
		int fireLocation, fireHouse;
		lineStream >> fireLocation;
		vector<Path> paths;
		while(lineStream >> fireHouse)
		{
			Path p;
			p.from = fireHouse;
			p.to = fireLocation;
			p.distance = g.GetShortestPathLength(p.from, p.to);
			p.nodes = g.GetShortestPath(p.from, p.to);		// does vector assignment do a copy or nothing?
			paths.push_back(p);		// does push_back do a copy or nothing?
		}

		cout << "Org\tDest\tTime\tPath" << endl;
		sort(paths.begin(), paths.end(), PathCmp);
		for(vector<Path>::iterator iter = paths.begin(); iter != paths.end(); iter++)
		{
			cout << iter->from << '\t' << iter->to << '\t' << iter->distance;
			for(int i = 0; i < iter->nodes.size(); i++)
				cout << '\t' << iter->nodes[i];
			cout << endl;
		}

		if(caseCount > 0)
			cout << endl;
	}
	return 0;
}
