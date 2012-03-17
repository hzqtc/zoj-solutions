#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 80;
const int COUNT = 100;

class query_term
{
public:
	const query_term& operator=(const string& s);
	bool match(const char* s);
private:
	char unsign[MAX];
	int un_size;
	char positive[MAX];
	int pos_size;
	char negative[MAX];
	int neg_size;
};

class query
{
public:
	query(const string& s);
	bool match(const char* s);
private:
	query_term term[COUNT];
	int term_count;
};

int main()
{
	const int LEN = 100;
	char word[COUNT][LEN];
	int word_count = 0;
	string q_str;

	int cmp(const void* a,const void* b);
	
	while(cin >> word[0] , strcmp(word[0],"#"))
	{
		word_count = 1;
		while(cin >> word[word_count] , strcmp(word[word_count],"*"))
			word_count++;
		qsort(word,word_count,sizeof(char) * LEN,cmp);

		while(cin >> q_str , q_str != "**")
		{
			query q(q_str);
			int i;
			for(i = 0;i<word_count;i++)
			{
				if(q.match(word[i]))
				{
					cout << word[i] << endl;
					break;
				}
			}
			if(i == word_count)
				cout << "NONE" << endl;
		}
		cout << '$' << endl;
	}
}

int cmp(const void* a,const void* b)
{
	return strcmp((char*)a,(char*)b);
}

query::query(const string& s)
{
	this->term_count = 0;
	string temp = "";
	int i = 0;

	while(s.find_first_of('|',i) != string::npos)
	{
		while(s[i] != '|')
		{
			temp += s[i];
			i++;
		}
		this->term[this->term_count++] = temp;
		temp = "";
		i++;
	}
	while(i < s.length())
	{
		temp += s[i];
		i++;
	}
	this->term[this->term_count++] = temp;
}

bool query::match(const char* s)
{
	for(int i = 0;i<this->term_count;i++)
	{
		if(this->term[i].match(s))
			return true;
	}

	return false;
}

bool query_term::match(const char* s)
{
	int i;
	string t(s);

	for(i=0;i<this->pos_size;i++)
	{
		if(t.find_first_of(positive[i]) == string::npos)
			break;
	}
	if(i < this->pos_size)
		return false;

	for(i=0;i<this->neg_size;i++)
	{
		if(t.find_first_of(negative[i]) != string::npos)
			break;
	}
	if(i < this->neg_size)
		return false;

	for(i=0;i<this->un_size;i++)
	{
		if(t.find_first_of(unsign[i]) != string::npos)
			break;
	}
	if(i < this->un_size)
		return true;
	else
		return false;
}

const query_term& query_term::operator=(const string& s)
{
	int i = 0;
	enum{un,pos,neg}flag = un;

	un_size = pos_size = neg_size = 0;

	while(i < s.length())
	{
		if(s[i] == '-')
			flag = neg;
		else if(s[i] == '+')
			flag = pos;
		else
		{
			if(flag == un)
				this->unsign[this->un_size++] = s[i];
			else if(flag == pos)
				this->positive[this->pos_size++] = s[i];
			else if(flag == neg)
				this->negative[this->neg_size++] = s[i];
		}
		i++;
	}

	return *this;
}
