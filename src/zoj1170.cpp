#include <iostream>

using namespace std;

void zhishu(int&,int&);

int main()
{
	string s1,s2;
	string* cmp;
	string* move;
	int index,skew;
	int common,com_temp;

	while(cin >> s1 , s1 != "-1")
	{
		cin >> s2;
		common = 0;

		cmp = &s1;
		move = &s2;
		for(skew=0;skew<cmp->length();skew++)
		{
			com_temp = 0;
			for(index=0;index<cmp->length()-skew;index++)
			{
				if((*move)[index] == (*cmp)[index + skew])
					com_temp++;
			}
			if(com_temp > common)
				common = com_temp;
		}

		cmp = &s2;
		move = &s1;
		for(skew=0;skew<cmp->length();skew++)
		{
			com_temp = 0;
			for(index=0;index<cmp->length()-skew;index++)
			{
				if((*move)[index] == (*cmp)[index + skew])
					com_temp++;
			}
			if(com_temp > common)
				common = com_temp;
		}

		cout << "appx(" << s1 << ',' << s2 << ") = ";
		int len = s1.length() + s2.length();
		common *= 2;
		zhishu(common,len);
		if(common == len)
			cout << 1 << endl;
		else if(common == 0)
			cout << 0 << endl;
		else
			cout << common << '/' << len << endl;
	}

	return 0;
}

void zhishu(int& a,int& b)
{
	int i = 2;
	while(i <= a && i <= b)
	{
		if(a % i == 0 && b % i == 0)
		{
			a /= i;
			b /= i;
		}
		else
			i++;
	}
}

