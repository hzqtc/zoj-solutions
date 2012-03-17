#include <iostream>
#include <string>

using namespace std;

int main()
{
	int column;
	string text;
	int i,row,k,len;
	
	while(cin>>column , column != 0)
	{
		cin>>text;
		len = text.size();
		row = len % column ? len / column + 1 : len / column;
		for(i=0;i<column;i++)
		{
			for(k=0;k<row;k++)
			{
				if(k % 2)
				{
					cout<<text[(k + 1) * column - 1 - i];
				}
				else
				{
					cout<<text[k * column + i];
				}
			}
		}
		cout<<endl;
	}

	return 0;
}
