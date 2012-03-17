#include <iostream>
#include <string>

using namespace std;

int main()
{
	const string replace_space = "    ";
	string line;
	int tab,trail_spa;
	int i;
	int casecount;
	
	cin >> casecount;
	while(casecount--)
	{
		tab = trail_spa = 0;
		while(getline(cin,line) , line != "##")
		{
			i = 0;
			while(i<line.length())
			{
				if(line[i] == '\t')
				{
					tab++;
					line.replace(i,1,replace_space);
					i += 4;
				}
				else
					i++;
			}
			i = line.length() - 1;
			while(line[i] == ' ')
			{
				trail_spa++;
				i--;
			}
		}
		cout << tab << " tab(s) replaced" << endl
			 << trail_spa << " trailing space(s) removed" << endl;
	}
	
	return 0;
}

