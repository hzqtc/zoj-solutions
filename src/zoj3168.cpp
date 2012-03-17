#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	while(cin >> line)
	{
		int z = 0, o = 0, j = 0, s = 0;
		int l = line.length();
		int i;
		string rest = "";
		for(i = 0; i < l; i++)
		{
			switch(line[i])
			{
			case 'Z':
				z++;
				break;
			case 'O':
				o++;
				break;
			case 'J':
				j++;
				break;
			case '7':
				s++;
				break;
			default:
				rest += line[i];
				break;
			}
		}
		cout << string(z, 'Z') << string(o, 'O') << string(j, 'J') << string(s, '7') << rest << endl;
	}
	return 0;
}
