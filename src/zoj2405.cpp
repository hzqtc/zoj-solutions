#include <iostream>

using namespace std;

int main()
{
	int toduo(int * d,int dec);
	int tohex(int * h,int dec);
	int getsum(int d);
	int getsum(int * d,int len);
	
	const int LEN = 16;
	int dec,hex[LEN],duo[LEN];
	int sum_d,sum_h,sum_u;
	int len;
	
	for(dec=2992;dec<10000;dec++)
	{
		sum_d = getsum(dec);
		len = tohex(hex,dec);
		sum_h = getsum(hex,len);
		len = toduo(duo,dec);
		sum_u = getsum(duo,len);
		
		if(sum_d == sum_h && sum_h == sum_u)
			cout<<dec<<endl;
	}
	
	return 0;
}

int getsum(int d)
{
	int sum = 0;
	
	while(d)
	{
		sum += d % 10;
		d /= 10;
	}
	
	return sum;
}

int getsum(int * d,int len)
{
	int sum = 0;
	
	for(int i = 0;i<len;i++)
	{
		sum += d[i];
	}
	
	return sum;
}

int toduo(int * d,int dec)
{
	int i = 0;
	
	while(dec)
	{
		d[i] = dec % 12;
		dec /= 12;
		i++;
	}
	
	return i;
}

int tohex(int * d,int dec)
{
	int i = 0;
	
	while(dec)
	{
		d[i] = dec % 16;
		dec /= 16;
		i++;
	}
	
	return i;
}
