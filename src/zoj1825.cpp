#include <iostream>
#include <string>
#include <vector>

using namespace std;

class hashtable
{
public:
	hashtable(int s, int (*fun)(const string&, int));		// constructor
	~hashtable();
	int add(const string& a);
	bool find(const string& a) const;
	const string& operator[](int index) const;
private:
	string* data;
	int (*hashfun)(const string&, int);
	int size;
	const string null_str;
};

int myhashfun(const string& s, int maxindex);

int main()
{
	const int max_word = 240003;
	hashtable words(max_word, myhashfun);
	vector<string> collect;
	string tmp;
	
	while(cin >> tmp)
	{
		words.add(tmp);
		collect.push_back(tmp);
	}

	vector<string>::iterator iter = collect.begin();
	while(iter != collect.end())
	{
		tmp = *iter++;
		for(int j = 1;j<tmp.length();j++)
		{
			string sub1 = tmp.substr(0, j);
			string sub2 = tmp.substr(j, tmp.length() - j);
			if(words.find(sub1) && words.find(sub2))
			{
				cout << tmp << endl;
				break;
			}
		}
	}

	return 0;
}

int myhashfun(const string& s, int maxindex)
{
	int pos = 0;
	for(int i = 0;i<s.length();i++)
	{
		pos = (pos << 5) + (s[i] - 'a');
		while(pos > maxindex)
			pos -= maxindex;
	}
	return pos;
}

hashtable::hashtable(int s, int(*fun)(const string&, int)) : hashfun(fun), size(s), null_str("")
{
	this->data = new string[size];
}

hashtable::~hashtable()
{
	delete[] this->data;
}

int hashtable::add(const string& a)
{
	int index = this->hashfun(a, this->size);
	int collision = 0;
	while(this->data[index] != this->null_str)
	{
		index += 2 * ++collision - 1;
		while(index > this->size)
			index -= this->size;
	}
	// cout << "Add " << a << " at " << index << endl;
	this->data[index] = a;
	return index;
}

bool hashtable::find(const string& a) const
{
	int index = this->hashfun(a, this->size);
	int collision = 0;
	while(this->data[index] != this->null_str)
	{
		if(this->data[index] == a)
			return true;

		index += 2 * ++collision - 1;
		while(index > this->size)
			index -= this->size;
	}
	return false;
}

const string& hashtable::operator[](int index) const
{
	if(index < this->size)
		return this->data[index];
	else
		return this->null_str;
}

