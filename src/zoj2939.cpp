#include <iostream>
#include <string>

using namespace std;

// class to translate roman numberal into integer and do the reverse
class RomanNumberal
{
public:
	RomanNumberal(const string& s)
	{
		PhraseNumber(s);
	}

	RomanNumberal(int i)
	{
		PhraseSource(i);
	}

	void SetSource(const string& s)
	{
		PhraseNumber(s);
	}

	const string& GetSource()
	{
		return source;
	}

	void SetNumber(int i)
	{
		PhraseSource(i);
	}

	int GetNumber()
	{
		return number;
	}
private:
	void PhraseNumber(const string& s)
	{
		source = s;
		number = 0;

		char c, nc;
		unsigned int i = 0;
		while(i < s.length())
		{
			switch(c = s[i])
			{
			case 'I':		// 1
				nc = s[i + 1];
				if(nc == 'V')
				{
					number += 4;
					i++;
				}
				else if(nc == 'X')
				{
					number += 9;
					i++;
				}
				else
					number += 1;
				break;
			case 'V':		// 5
				number += 5;
				break;
			case 'X':		// 10
				nc = s[i + 1]; 
				if(nc == 'L')
				{
					number += 40;
					i++;
				}
				else if(nc == 'C')
				{
					number += 90;
					i++;
				}
				else
					number += 10;
				break;
			case 'L':		// 50
				number += 50;
				break;
			case 'C':		// 100
				nc = s[i + 1]; 
				if(nc == 'D')
				{
					number += 400;
					i++;
				}
				else if(nc == 'M')
				{
					number += 900;
					i++;
				}
				else
					number += 100;
				break;
			case 'D':		// 500
				number += 500;
				break;
			case 'M':		// 1000
				number += 1000;
				break;
			}
			i++;
		}
	}

	void PhraseSource(int i)
	{
		number = i;
		source = "";

		while(number >= 1000)
		{
			source += 'M';
			number -= 1000;
		}
		while(number >= 900)
		{
			source += "CM";
			number -= 900;
		}
		while(number >= 500)
		{
			source += 'D';
			number -= 500;
		}
		while(number >= 400)
		{
			source += "CD";
			number -= 400;
		}
		while(number >= 100)
		{
			source += 'C';
			number -= 100;
		}
		while(number >= 90)
		{
			source += "XC";
			number -= 90;
		}
		while(number >= 50)
		{
			source += 'L';
			number -= 50;
		}
		while(number >= 40)
		{
			source += "XL";
			number -= 40;
		}
		while(number >= 10)
		{
			source += 'X';
			number -= 10;
		}
		while(number >= 9)
		{
			source += "IX";
			number -= 9;
		}
		while(number >= 5)
		{
			source += 'V';
			number -= 5;
		}
		while(number >= 4)
		{
			source += "IV";
			number -= 4;
		}
		while(number >= 1)
		{
			source += 'I';
			number -= 1;
		}

		number = i;
	}

	string source;
	int number;
};

int main()
{
	unsigned int numCount;
	int caseIndex = 1;
	while(cin >> numCount, numCount > 0)
	{
		int sum = 0;
		string s;
		while(numCount--)
		{
			cin >> s;
			sum += RomanNumberal(s).GetNumber();
		}
		cout << "Case " << RomanNumberal(caseIndex++).GetSource() << ": ";
		cout << RomanNumberal(sum).GetSource() << endl;
	}
	return 0;
}
