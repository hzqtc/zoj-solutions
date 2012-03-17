#include <iostream>
#include <string>
#include <map>

using namespace std;

bool getword(string& s);
int gcd(int a,int b);
bool isalpha(char c);
void tolower(string& s);

int main()
{
	string w;
	map<string,int> word_map;
	int unicount = 0;
	int total = 0,term = 0;
	
	while(getword(w))
	{
		if(w == "BULLSHIT")
		{
			total += unicount;
			unicount = 0;
			word_map.clear();
			term++;
		}
		else
		{
			tolower(w);
			word_map[w]++;
			if(word_map[w] == 1)
				unicount++;
		}
	}
	
	int c = gcd(total,term);
	total /= c;
	term /= c;
	
	cout << total << " / " << term << endl;
	
	return 0;
}

int gcd(int a,int b)
{
	int c;
	
	while(c = a % b)
	{
		a = b;
		b = c;
	}
	
	return b;
}

bool getword(string& s)
{
	s = "";
	char c;
	
	while(cin >> c)
	{
		if(isalpha(c))
		{
			s = c;
			break;
		}
	}
	
	if(s == "")
		return false;
	
	while((c = getchar()) != EOF)
	{
		if(!isalpha(c))
			return true;
		else
			s += c;
	}
		
	return false;
}

bool isalpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void tolower(string& s)
{
	for(int i = 0;i<s.length();i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] -= ('A' - 'a');
	}
}

