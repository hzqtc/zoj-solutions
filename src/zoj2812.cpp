#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const int MAX = 256;
	int sum;
	char packet[MAX];
	int i;
	
	void getline(char * s);
	
	while(getline(packet) , packet[0] != '#')
	{
		sum = 0;
		for(i=0;i<strlen(packet);i++)
		{
			sum += (i + 1) * (packet[i] == ' ' ? 0 : packet[i] - 'A' + 1);
		}
		cout<<sum<<endl;
	}
	
	return 0;
}

void getline(char * s)
{
	int i = 0;
	char c;
	
	while((c = getchar()) != '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
}
