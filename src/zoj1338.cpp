#include <iostream>
#include <iomanip>

using namespace std;

struct seq
{
	int length;
	int count;
	
}sequp,seqdown,zero = {0,0};

enum {up,down,none} up_or_down;

int main()
{
	int data,datacount,predata;
	int len;
	
	while(cin >> predata , predata > 0)
	{
		seqdown = sequp = zero;
		up_or_down = none;
		len = 1;
		datacount = 1;
		while(cin >> data , data > 0)
		{
			if(up_or_down == up)
			{
				if(data < predata)
				{
					sequp.count++;
					sequp.length += len - 1;
					len = 1;
					up_or_down = down;
				}
			}
			else if(up_or_down == down)
			{
				if(data > predata)
				{
					seqdown.count++;
					seqdown.length += len - 1;
					len = 1;
					up_or_down = up;
				}
			}
			else
			{
				if(data > predata)
					up_or_down = up;
				else if(data < predata)
					up_or_down = down;
			}
				
			predata = data;
			datacount++;
			len++;
		}
		if(up_or_down == up)
		{
			sequp.count++;
			sequp.length += len - 1;
		}
		else if(up_or_down == down)
		{
			seqdown.count++;
			seqdown.length += len - 1;
		}
		cout << setprecision(6) << setiosflags(ios::fixed);
		cout << "Nr values = " << datacount << ":  " 
			 << (sequp.count ? (double)sequp.length / (double)sequp.count : 0)
			 << ' ' 
			 << (seqdown.count ? (double)seqdown.length / (double)seqdown.count : 0)
			 << endl;
	}
	
	return 0;
}

