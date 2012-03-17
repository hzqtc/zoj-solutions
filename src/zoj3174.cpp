#include <iostream>

using namespace std;

int daysLeapYear[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int daysNormalYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapyear(int year)
{
	if(year % 100 == 0)
		return year % 400 == 0;
	else
		return year % 4 == 0;
}

bool judge(int year, int n)
{
	return (n * n == year % 100)  || (n * n == year % 1000);
}

int main()
{
	int cse;
	cin >> cse;
	while(cse--)
	{
		int from, to;
		int count = 0;
		cin >> from >> to;
		for(int year = from; year <= to; year++)
		{
			for(int month = 1; month <= 12; month++)
			{
				int totalDays = (isLeapyear(year)? daysLeapYear: daysNormalYear)[month - 1];
				for(int day = 1; day <= totalDays; day++)
				{
					if(judge(year, month) == true && judge(year, day) == true)
						count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
