#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

string genchilddata(const string& name, const string& size);
void makespace(string& s);

class node
{
public:
	node(const node& copy);
	node(const string& data);
	void addchild(node* child);
	void list_tree() const;
	void clear();

	node* nextsibling;
	node* firstchild;
	node* parent;
	bool isdir;
	int size;
	int selfsize;
	string name;
};

int main()
{
	string line;
	node* parentdir = NULL;
	node* root = NULL;
	queue<node*> parnodes;		// queue to store the directions(which are added children to)

	while(getline(cin, line))
	{
		if(line == "")
			continue;
		makespace(line);
		istringstream datasource(line);

		if(line[0] != '(')	// new case begin
		{
			root->list_tree();
			root->clear();
			root = new node(line);
			parentdir = root;
		}
		else
		{
			string childdata, childname, childsize;
			node* newnode = NULL;

			while(datasource >> childname >> childsize)
			{
				childdata = genchilddata(childname, childsize);

				if(childdata != " ")
				{
					parentdir->addchild(newnode = new node(childdata));
					if(newnode->isdir)
						parnodes.push(newnode);
				}

				if(childsize[childsize.length() - 1] == ')' && !(parnodes.empty()))	// goto next direction
				{
					parentdir = parnodes.front();
					parnodes.pop();
				}
			}

		}
	}
	root->list_tree();		// last case
	root->clear();

	return 0;
}

string genchilddata(const string& name, const string& size)
{
	string data;

	if(name[0] == '(')
		data = name.substr(1, name.length() - 1);
	else
		data = name;
	data += ' ';
	if(size[size.length() - 1] == ')')
		data += size.substr(0, size.length() - 1);
	else
		data += size;

	return data;
}

void makespace(string& s)		// add space between '(' and ')', for "()" have no space seperate them
{
	size_t p = 0;
	const string pattern = "()";
	const string replace = "( )";
	while((p = s.find(pattern, p)) != string::npos)
	{
		s.erase(p, 2);
		s.insert(p, replace);
		p += 3;
	}
}

node::node(const node& copy)	// copy constructor, only selfsize and name are copied
{
	this->name =copy.name;
	this->size = this->selfsize = copy.size;
	this->isdir = copy.isdir;
	this->nextsibling = this->firstchild = this->parent = NULL;
}

node::node(const string& data)	// construct from a string contain name and size
{
	istringstream iss(data);
	iss >> this->name >> this->selfsize;
	this->size = this->selfsize;
	this->nextsibling = this->firstchild = this->parent = NULL;
	this->isdir = this->name[0] == '*' ? true : false;
}

void node::addchild(node* child)
{
	child->parent = this;					// set newnode's parent to current node
	int addsize = child->selfsize;

	node** iter = &(this->firstchild);		// find the end of children
	while(*iter)
		iter = &((*iter)->nextsibling);
	*iter = child;

	node* iter2 = this;						// add size to each parent direction
	while(iter2)
	{
		iter2->size += addsize;
		iter2 = iter2->parent;
	}
}

void node::list_tree() const
{
	if(this != NULL)
	{
		string indent;
		node* iter = this->parent;
		while(iter)
		{
			if(iter->nextsibling)
				indent = "|       " + indent;
			else
				indent = "        " + indent;
			iter = iter->parent;
		}
		cout << indent << "|_" << this->name << '[' << this->size << ']' << endl;

		iter = this->firstchild;
		while(iter)
		{
			iter->list_tree();
			iter = iter->nextsibling;
		}
	}
}

void node::clear()
{
	if(this != NULL)
	{
		node* iter = this->firstchild;
		node* copy;
		
		while(iter)
		{
			copy = iter->nextsibling;
			iter->clear();
			iter = copy;
		}

		delete this;
		this->firstchild = this->nextsibling = this->parent = NULL;
	}
}
