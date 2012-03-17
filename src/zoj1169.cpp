#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

string& formatkey(string& key);
string& formattext(string& text);
string encrypt(const string& s, char alphabet[5][5]);
void print_encry(const string& s, char alphabet[5][5]);

int main()
{
	string key;
	string text;
	string encoded;
	int i;

	while(cin >> key, key != "999")
	{
		char alphabet[5][5] = {{'\0'}};
		set<char> uniquechar;

		formatkey(key);
		for(i=0;i<key.length();i++)
		{
			alphabet[i / 5][i % 5] = key[i];
			uniquechar.insert(key[i]);
		}
		uniquechar.insert('J');		// in order to jump 'J'
		for(char c = 'A';i < 25;i++)
		{
			while(uniquechar.find(c) != uniquechar.end())
				c++;
			alphabet[i / 5][i % 5] = c;
			uniquechar.insert(c);
			c++;
		}

		do
		{
			getline(cin, text);
		}while(text == "");
		formattext(text);
		print_encry(text, alphabet);
	}

	return 0;
}

void print_encry(const string& s, char alphabet[5][5])
{
	istringstream plain(s);
	string tmp;
	plain >> tmp;
	cout << encrypt(tmp, alphabet);
	while(plain >> tmp)
		cout << ' ' << encrypt(tmp, alphabet);
	cout << endl;
}

string& formatkey(string& key)
{
	set<char> keyalpha;
	int i = 0;
	
	while(i < key.length())
	{
		if(key[i] == 'J')
			key[i] = 'I';

		if(keyalpha.find(key[i]) == keyalpha.end())
			keyalpha.insert(key[i++]);
		else
			key.erase(i, 1);
	}
	
	return key;
}

string& formattext(string& text)
{
	int i = 0;
	while(i < text.length())	// remove all blank space
	{
		if(text[i] == ' ')
			text.erase(i, 1);
		else if(text[i] == 'J')	// all J turned into I
			text[i++] = 'I';
		else
			i++;
	}
	
	i = 1;
	while(i < text.length())	// deal with double letters
	{
		if(text[i] == text[i - 1])
		{
			if(i < text.length() - 1 && text[i] != 'Q')
				text.insert(i, "Q");
			else
				text.insert(i, "Z");
			i++;
		}
		else
			i++;
	}
	
	if(text.length() % 2)		// deal with odd letter
	{
		if(text[text.length() - 1] == 'Q')
			text.insert(text.length(), "Z");
		else
			text.insert(text.length(), "Q");
	}
	
	i = 2;
	while(i < text.length())	// add blank space to seperate the string into two letter groups
	{
		text.insert(i, " ");
		i += 3;
	}

	return text;
}

string encrypt(const string& s, char alphabet[5][5])
{
	struct
	{
		int x, y;
	}pos1, pos2;
	string re;

	for(pos1.x=0;pos1.x<5;pos1.x++)
	{
		for(pos1.y=0;pos1.y<5;pos1.y++)
		{
			if(s[0] == alphabet[pos1.x][pos1.y])
				goto findanother;
		}
	}
findanother:
	for(pos2.x=0;pos2.x<5;pos2.x++)
	{
		for(pos2.y=0;pos2.y<5;pos2.y++)
		{
			if(s[1] == alphabet[pos2.x][pos2.y])
				goto findfinish;
		}
	}
	
findfinish:
	if(pos1.x == pos2.x)
	{
		pos1.y++;
		if(pos1.y == 5)
			pos1.y = 0;
		pos2.y++;
		if(pos2.y == 5)
			pos2.y = 0;
		re = alphabet[pos1.x][pos1.y];
		re += alphabet[pos2.x][pos2.y];
	}
	else if(pos1.y == pos2.y)
	{
		pos1.x++;
		if(pos1.x == 5)
			pos1.x = 0;
		pos2.x++;
		if(pos2.x == 5)
			pos2.x = 0;
		re = alphabet[pos1.x][pos1.y];
		re += alphabet[pos2.x][pos2.y];
	}
	else
	{
		re = alphabet[pos1.x][pos2.y];
		re += alphabet[pos2.x][pos1.y];
	}
		
	return re;
}
