#include <iostream>
#include <string>

using namespace std;

enum type{hole,flor,wall,l_mount,r_mount};

type choosetype(const char& c);
int get_chance(int index,int dir);

const int MAX = 100;
type m[MAX];
int m_len;

int main()
{
	string machine;
	
	while(cin >> machine , machine != "#")
	{
		int total_chance = 0;
		
		m[0] = hole;//两边界个加上一个hole
		m_len = machine.length();
		for(int i = 1;i<=m_len;i++)
			m[i] = choosetype(machine[i - 1]);
		m[m_len + 1] = hole;
			
		for(int start = 1;start<=m_len;start++)
		{
			int chance = 0;
			switch(m[start])
			{
			case hole:
				chance = 100;
				break;
			case flor:
				chance = 0;
				break;
			case wall:
				chance = (get_chance(start,1) + get_chance(start,2)) / 2;
				break;
			case l_mount:
				chance = get_chance(start,1);
				break;
			case r_mount:
				chance = get_chance(start,2);
				break;
			}
			total_chance += chance;
		}
		cout << total_chance / m_len << endl;
	}

	return 0;
}

int get_chance(int index,int dir)
{
	if(dir == 1)//left
	{
		int i = index - 1;
		while(i >= 0)
		{
			if(m[i] == hole)
				return 100;
			else if(m[i] != flor)
				return 0;
			i--;
		}
	}
	else if(dir == 2)//right
	{
		int i = index + 1;
		while(i <= m_len + 1)
		{
			if(m[i] == hole)
				return 100;
			else if(m[i] != flor)
				return 0;
			i++;
		}
	}
}

type choosetype(const char& c)
{
	switch(c)
	{
	case '.':
		return hole;
	case '_':
		return flor;
	case '|':
		return wall;
	case '/':
		return l_mount;
	case '\\':
		return r_mount;
	}
}
