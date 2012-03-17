#include <iostream>

using namespace std;

struct IP
{
	int byte[4];
};

int ipcount;
const int MAX = 1000;
IP ipadress[MAX];

const int BITMAX = 8;
const int mask = 1;

int checksamebits(int byteindex);

int main()
{
	IP ipmask;
	IP leastip;
	int samelength;

	while(cin >> ipcount)
    {
		int i;

		for(i=0;i<ipcount;i++)
		{
			cin >> ipadress[i].byte[0];	getchar();
			cin >> ipadress[i].byte[1];	getchar();
			cin >> ipadress[i].byte[2];	getchar();
			cin >> ipadress[i].byte[3];
		}
		
		samelength = checksamebits(1);
		if(samelength == 8)
		{
			samelength += checksamebits(2);
			if(samelength == 16)
			{
				samelength += checksamebits(3);
				if(samelength == 24)
					samelength += checksamebits(4);
			}

		}

		leastip.byte[0] = leastip.byte[1] = leastip.byte[2] = leastip.byte[3] = 0;
		ipmask.byte[0] = ipmask.byte[1] = ipmask.byte[2] = ipmask.byte[3] = 0;

		for(i=0;i<samelength;i++)
		{
			leastip.byte[i / 8] |= ipadress[0].byte[i / 8] & (mask << (BITMAX - (i % 8) - 1));//置为与所有IP地址相同
			ipmask.byte[i / 8] |= (mask << (BITMAX - (i % 8) - 1));//总是置为1
		}
		cout << leastip.byte[0] << '.' << leastip.byte[1] << '.' << leastip.byte[2] << '.' << leastip.byte[3] << endl;
		cout << ipmask.byte[0] << '.' << ipmask.byte[1] << '.' << ipmask.byte[2] << '.' << ipmask.byte[3] << endl;
    }

    return 0;
}

int checksamebits(int byteindex)
{
	byteindex--;
	int i,j,samelen = 0;

	for(j=BITMAX - 1;j>=0;j--)
	{
		for(i=1;i<ipcount;i++)
		{
			if(((mask << j) & ipadress[i].byte[byteindex]) != ((mask << j) & ipadress[i - 1].byte[byteindex]))
				break;
		}
		if(i == ipcount)
			samelen++;
		else
			break;;
	}
	return samelen;
}

