#include <iostream>

using namespace std;

int main()
{
	const int mask = 0x1f;//11111 in binary
	int pc,accu;
	int mem[32];
	int instru,memindex;
	int i,j;
	char s[10];
	
	while(cin >> s)
	{
		mem[0] = 0;
		for(j=0;j<8;j++)
			mem[0] = mem[0] * 2 + (s[j] - '0');

		for(i=1;i<32;i++)
		{
			mem[i] = 0;
			cin >> s;
			for(j=0;j<8;j++)
				mem[i] = mem[i] * 2 + (s[j] - '0');
		}
		
		pc = accu = 0;
		while((instru = mem[pc] >> 5) != 7)
		{
			memindex= mask & mem[pc];
			pc++;
			pc &= mask;
			accu &= 0xff; 
			switch(instru)
			{
				case 0:
					mem[memindex] = accu;
					break;
				case 1:
					accu = mem[memindex];
					break;
				case 2:
					if(accu == 0)
						pc = memindex;
					break;
				case 4:
					accu--;
					break;
				case 5:
					accu++;
					break;
				case 6:
					pc = memindex;
					break;
				default:
					break;
			}
		}
		for(i = 7;i>=0;i--)
			cout << ((accu >> i) & 1);
		cout << endl;
	}
	
	return 0;
}
