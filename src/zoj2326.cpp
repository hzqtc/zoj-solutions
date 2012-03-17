#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct edge
{
	int v1, v2;
	double weight;
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
	double capable;
	cin >> capable;
	map<string, int> houseindex;
	edge tmp;
	
	int n, m;
	int number = 1;
	cin >> n;
	for(int i = 0;i<n;i++)
	{
		string name;
		cin >> name;
		houseindex[name] = number++;
	}
	cin >> m;
	priority_queue<edge> road;
	while(m--)
	{
		string n;
		cin >> n;
		tmp.v1 = houseindex[n];
		cin >> n;
		tmp.v2 = houseindex[n];
		cin >> tmp.weight;
		road.push(tmp);
	}
	
	DisjSet house(n);
	double need = 0;
	while(house.getsetsize(1) < n)
	{
		tmp = road.top();
		road.pop();
		if(house.find(tmp.v1) != house.find(tmp.v2))
		{
			need += tmp.weight;
			house.merge(tmp.v1, tmp.v2);
		}
	}
	
	if(need > capable)
		cout << "Not enough cable" << endl;
	else
	{
		cout << "Need ";
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << need << " miles of cable" << endl;
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
/*
100.0
4
Jones
Smiths
Howards
Wangs
5
Jones Smiths 2.0
Jones Howards 4.2
Jones Wangs 6.7
Howards Wangs 4.0
Smiths Wangs 10.0
*/
