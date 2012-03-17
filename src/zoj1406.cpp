#include <iostream>
#include <queue>

#define index(x) ((x) - 'A' + 1)

using namespace std;

struct edge
{
	char v1, v2;
	int weight;
};

class DisjSet
{
public:
	DisjSet(int size)
	{
		this->data = new int[size + 1];
		for(int i = 1;i<=size;i++)
			this->data[i] = -1;
	}
	~DisjSet()
	{
		delete[] this->data;
	}
	int find(int f);			// return its root's index
	int merge(int a, int b);	// merge two set to one and return new root's index
	int getsetsize(int f);
private:
	int* data;
};

bool operator<(const edge& a, const edge& b);

int main()
{
	const int villagemax = 32;
	int n;

	while(cin >> n, n > 0)
	{
		priority_queue<edge> road;
		edge tmp;
		int cost = 0;
		for(int i = 1;i < n;i++)		// n - 1 loops
		{
			int c;
			cin >> tmp.v1 >> c;
			while(c--)
			{
				cin >> tmp.v2 >> tmp.weight;
				road.push(tmp);
			}
		}
		
		DisjSet village(villagemax);
		while(village.getsetsize(1) < n)		// while completed, only one set with size n exists
		{
			tmp = road.top();
			road.pop();
			if(village.find(index(tmp.v1)) == village.find(index(tmp.v2)))	// in the same set will make a cycle
				continue;

			// cout << "Choose the edge from " << tmp.v1 << " to " << tmp.v2 << ", weight of which is: " << tmp.weight << endl;
			cost += tmp.weight;
			village.merge(index(tmp.v1), index(tmp.v2));
		}

		cout << cost << endl;
	}

	return 0;
}

bool operator<(const edge& a, const edge& b)
{
	return a.weight > b.weight;		// make the priority_queu choose the min edge
}

int DisjSet::find(int f)
{
	if(this->data[f] <= 0)
		return f;
	else
		return this->data[f] = this->find(this->data[f]);
}

int DisjSet::getsetsize(int f)
{
	while(this->data[f] > 0)
		f = this->data[f];
	return -this->data[f];
}

int DisjSet::merge(int a, int b)
{
	int root1 = this->find(a);
	int root2 = this->find(b);
	
	if(this->data[root1] < this->data[root2])
	{
		this->data[root1] += this->data[root2];
		this->data[root2] = root1;
		return root1;
	}
	else
	{
		this->data[root2] += this->data[root1];
		this->data[root1] = root2;
		return root2;
	}
}

