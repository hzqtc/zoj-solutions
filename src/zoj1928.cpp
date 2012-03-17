#include <iostream>

using namespace std;

int main()
{
	int position,degree;
	int c1,c2,c3;

	while(cin>>position>>c1>>c2>>c3 , position | c1 | c2 | c3)
	{
		degree = 2 * 40;
		if(position > c1)
			degree += position - c1;
		else
			degree += 40 - (c1 - position);
		position = c1;
		degree += 40;
		if(position > c2)
			degree += 40 - (position - c2);
		else
			degree += c2 - position;
		position = c2;
		if(position > c3)
			degree += position - c3;
		else
			degree += 40 - (c3 - position);
		cout<<degree * 9<<endl;
	}

	return 0;
}