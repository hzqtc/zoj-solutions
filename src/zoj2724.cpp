#include <cstdio>
#include <cstring>
#include <queue>

class message
{
public:
	message();
	const message& read();
	void print() const;
	friend bool operator<(const message& a,const message& b);
private:
	char name[100];
	int parameter,priority;
};

using namespace std;

int main()
{
	priority_queue<message> msg;
	char cmd[10];
	message temp;
	
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd,"GET"))
		{
			if(msg.empty())
				puts("EMPTY QUEUE!");
			else
			{
				msg.top().print();
				msg.pop();
			}
		}
		else if(!strcmp(cmd,"PUT"))
			msg.push(temp.read());
	}
	
	return 0;
}

message::message()
{
	strcpy(this->name,"");
	this->parameter = this->priority = 0;
}

const message& message::read()
{
	scanf("%s %d %d",this->name,&this->parameter,&this->priority);
	
	return *this;
}

void message::print() const
{
	printf("%s %d\n",this->name,this->parameter);
}

bool operator<(const message& a,const message& b)
{
	return a.priority > b.priority;
}

