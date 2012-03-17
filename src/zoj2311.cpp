#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main()
{
	map<string, int> number;
	number["negative"] = -1;
	number["zero"] = 0;
	number["one"] = 1;
	number["two"] = 2;
	number["three"] = 3;
	number["four"] = 4;
	number["five"] = 5;
	number["six"] = 6;
	number["seven"] = 7;
	number["eight"] = 8;
	number["nine"] = 9;
	number["ten"] = 10;
	number["eleven"] = 11;
	number["twelve"] = 12;
	number["thirteen"] = 13;
	number["fourteen"] = 14;
	number["fifteen"] = 15;
	number["sixteen"] = 16;
	number["seventeen"] = 17;
	number["eighteen"] = 18;
	number["nineteen"] = 19;
	number["twenty"] = 20;
	number["thirty"] = 30;
	number["forty"] = 40;
	number["fifty"] = 50;
	number["sixty"] = 60;
	number["seventy"] = 70;
	number["eighty"] = 80;
	number["ninety"] = 90;

	string line;

	while(getline(cin, line), line != "")
	{
		istringstream linestream(line);
		string token;
		int part = 0;
		int total = 0;
		bool negative = false;
		while(linestream >> token)
		{
			if(token == "negative")
				negative = true;
			else if(token == "hundred")
			{
				part *= 100;
			}
			else if(token == "thousand")
			{
				total += part * 1000;
				part = 0;
			}
			else if(token == "million")
			{
				total += part * 1000000;
				part = 0;
			}
			else if(number[token] >= 0 && number[token] <= 90)
			{
				part += number[token];
			}
		}
		total += part;
		if(negative)
			total = -total;
		cout << total << endl;
	}

	return 0;
}
