#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 20000;
int tree[MAX] = {0};

bool testComplete()
{
	tree[0] = 1;							// parent of root must be set to non-zero
	for(int i = 1; i < MAX; i++)
	{
		if(tree[i] > 0 && tree[i / 2] == 0)	// check whether a tree node has a parent node
			return false;
	}
	return true;
}

void printTree()
{
	bool first = true;
	for(int i = 1; i < MAX; i++)
	{
		if(tree[i] > 0)
		{
			if(first)
			{
				cout << tree[i];
				first = false;
			}
			else
				cout << ' ' << tree[i];
		}
	}
	cout << endl;
}

int main()
{
	bool bad = false;
	string node;
	while(cin >> node)
	{
		if(node == "()")
		{
			if(!bad && testComplete())
				printTree();
			else
				cout << "not complete" << endl;

			memset(tree, 0, MAX * sizeof(int));
			bad = false;
		}
		else
		{
			int value = 0;
			int index = 1;
			int i;
			for(i = 1; node[i] != ','; i++)
				value = value * 10 + node[i] - '0';
			for(i++; node[i] != ')'; i++)
			{
				index *= 2;			// left child's index = parent's index * 2
				if(node[i] == 'R')	// right child's index = parent's index * 2 + 1
					index++;
			}

			if(tree[index] == 0)
				tree[index] = value;
			else
				bad = true;
		}
	}
	return 0;
}

