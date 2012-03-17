#include <iostream>
#include <set>

using namespace std;

int main()
{
	int a, b, c, s;
	while(cin >> a, a > 0)
	{
		cin >> b >> c >> s;
		char bits[20] = {'\0'};
		set<int> exist;
		while(exist.find(s) == exist.end())		// s is not in the set.
		{
			exist.insert(s);
			int mask = 0x8000;
			for(int i = 0; i < 16; i++)
			{
				int tmp = mask & s;
				tmp = !!tmp;					// set tmp to binary(0 or 1)
				if(bits[i] == '\0')
					bits[i] = tmp + '0';
				else if(bits[i] != tmp + '0')
					bits[i] = '?';
				mask >>= 1;
			}
			s  = (a * s + b) % c;
		}
		for(int i = 0; i < 16; i++)
			cout << bits[i];
		cout << endl;
	}
	return 0;
}
