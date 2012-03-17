#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

const int MONTH = 12;

void prime(int* a,int& max);
void remove_trail_sapce(string& s);

int main()
{
	int bircount[MONTH],bircount_ori[MONTH];
	int maxbir;
	int peo;
	int i,j;

	while(cin >> peo , peo > 0)
	{
		for(i=0;i<MONTH;i++)
			bircount[i] = 0;

		maxbir = 0;
		while(peo--)
		{
			int day;
			string mon;

			cin >> mon >> day;

			if(mon == "January")		bircount[day <= 21 ? 9  : 10]++;
			else if(mon == "February")	bircount[day <= 20 ? 10 : 11]++;
			else if(mon == "March")		bircount[day <= 19 ? 11 :  0]++;
			else if(mon == "April")		bircount[day <= 20 ? 0  :  1]++;
			else if(mon == "May")		bircount[day <= 21 ? 1  :  2]++;
			else if(mon == "June")		bircount[day <= 22 ? 2  :  3]++;
			else if(mon == "July")		bircount[day <= 22 ? 3  :  4]++;
			else if(mon == "August")	bircount[day <= 22 ? 4  :  5]++;
			else if(mon == "September")	bircount[day <= 22 ? 5  :  6]++;
			else if(mon == "October")	bircount[day <= 22 ? 6  :  7]++;
			else if(mon == "November")	bircount[day <= 22 ? 7  :  8]++;
			else if(mon == "December")	bircount[day <= 22 ? 8  :  9]++;
		}
		memcpy(bircount_ori,bircount,MONTH * sizeof(int));

		maxbir = 0;
		for(i=0;i<MONTH;i++)
		{
			if(bircount[i] > maxbir)
				maxbir = bircount[i];
		}
		prime(bircount,maxbir);

		for(i=maxbir;i>=0;i--)
		{
			string result;
			ostringstream re;
			re << ' ';
			for(j=0;j<MONTH;j++)
			{
				if(bircount[j] == i && i != 0)
				{
					if(bircount_ori[j] < 10)
						re << ' '; 
					re << bircount_ori[j];
				}
				else if(bircount[j] > i)
					re << "XX";
				else
					re << "  ";
				if(j != MONTH - 1)
					re << "  ";
			}
			result = re.str();
			remove_trail_sapce(result);
			cout << result << endl;
		}
		cout << "------------------------------------------------" << endl;
		cout << " Ar  Ta  Ge  Ca  Le  Vi  Li  Sc  Sa  Ca  Aq  Pi" << endl << endl;
	}

	return 0;
}


void prime(int* a,int& max)
{
	for(int i = 2;i<=max;i++)
	{
        while(!(a[0] % i || a[1] % i || a[2] % i || a[3] % i || a[4] % i || a[5] % i || a[6] % i || a[7] % i || a[8] % i || a[9] % i || a[10] % i || a[11] % i))
        {
            a[0] /= i;
			a[1] /= i;
			a[2] /= i;
			a[3] /= i;
			a[4] /= i;
			a[5] /= i;
			a[6] /= i;
			a[7] /= i;
			a[8] /= i;
			a[9] /= i;
			a[10] /= i;
			a[11] /= i;
            max /= i;
        }
	}
}


void remove_trail_sapce(string& s)
{
	int i = s.length() - 1;

	while(s[i] == ' ')
	{
		s.erase(i,i);
		i = s.length() - 1;
	}
}