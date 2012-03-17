#include <iostream>
#include <cstring>

using namespace std;

inline bool isvowel(char c);

int main()
{
	const int LEN = 32;
	char word[LEN];
	char c,fc;
	int index;
	bool vowel;
	bool pass;
	int three;

	while(cin>>word ,strcmp(word,"end"))
	{
		pass = true;
		three = 1;
		fc = word[0];
		if(isvowel(fc))
			vowel = true;
		else
			vowel = false;

		for(index=1;index<strlen(word);index++)
		{
			c = word[index];

			if(c == fc && c != 'e' && c != 'o')
			{
				pass = false;
				break;
			}

			if(isvowel(c))
			{
				vowel = true;
				if(isvowel(fc))
				{
					three++;
					if(three == 3)
					{
						pass = false;
						break;
					}
				}
				else
					three = 1;
			}
			else
			{
				if(!(isvowel(fc)))
				{
					three++;
					if(three == 3)
					{
						pass = false;
						break;
					}
				}
				else
					three = 1;
			}

			fc = c;
		}
		if(pass == true && vowel == true)
			cout<<'<'<<word<<"> is acceptable."<<endl;
		else
			cout<<'<'<<word<<"> is not acceptable."<<endl;
	}

	return 0;
}

inline bool isvowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
