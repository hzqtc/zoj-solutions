#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	int linechar;
	bool newline;

	newline = true;
	linechar = 0;
	while(cin>>word)
	{
		if(word == "<br>")
		{
			cout<<'\n';
			newline = true;
		}
		else if(word == "<hr>")
		{
			if(newline == false)
				cout<<'\n';
			cout<<"--------------------------------------------------------------------------------\n";
			newline = true;
		}
		else
		{
			if(newline == true)
			{
				cout<<word;
				linechar = word.size();
			}
			else
			{
				if(linechar + word.size() + 1 <= 80)
				{
					cout<<' '<<word;
					linechar += word.size() + 1;
				}
				else
				{
					cout<<'\n'<<word;
					linechar = word.size();
				}
			}
			newline = false;
		}
	}
	cout<<endl;

	return 0;
}
