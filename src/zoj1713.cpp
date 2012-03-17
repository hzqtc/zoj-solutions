#include <iostream>
#include <cstring>

using namespace std;

bool isvowel(char c);

int main()
{
	int vowel1,vowel2,vowel3;
	int i;
	const int MAX = 210;
	char line[MAX];
	
	while(cin.getline(line,MAX,'\n') , strcmp(line,"e/o/i") != 0)
	{
		i = 0;
		vowel1 = vowel2 = vowel3 = 0;
		while(line[i] != '/')
		{
			if(isvowel(line[i++]) == true)
			{
				vowel1++;
				while(isvowel(line[i]) == true)
					i++;
			}
		}
		i++;
		while(line[i] != '/')
		{
			if(isvowel(line[i++]) == true)
			{
				vowel2++;
				while(isvowel(line[i]) == true)
					i++;
			}
		}
		i++;
		while(line[i] != '\0')
		{
			if(isvowel(line[i++]) == true)
			{
				vowel3++;
				while(isvowel(line[i]) == true)
					i++;
			}
		}
		
		if(vowel1 != 5)
			putchar('1');
		else if(vowel2 != 7)
			putchar('2');
		else if(vowel3 != 5)
			putchar('3');
		else
			putchar('Y');
		cout<<endl;
	}
	
	return 0;
}

bool isvowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

