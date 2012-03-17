#include <iostream>

using namespace std;

struct window
{
	int left,top,right,bottom;
};

int main()
{
	const int MAX = 10;
	window win[MAX];
	int wincount,clickcount;
	int mouse_x,mouse_y;

	while(cin >> wincount , wincount > 0)
	{
		int i;
		for(i=0;i<wincount;i++)
			cin >> win[i].left >> win[i].top >> win[i].right >> win[i].bottom;
		cin >> clickcount;
		while(clickcount--)
		{
			cin >> mouse_x >> mouse_y;
			for(i=wincount-1;i>=0;i--)
			{
				if(win[i].left <= mouse_x && mouse_x <= win[i].right && win[i].top <= mouse_y && mouse_y <= win[i].bottom)
				{
					cout << i << endl;
					break;
				}
			}
			if(i < 0)
				cout << -1 << endl;
		}
	}

	return 0;
}

