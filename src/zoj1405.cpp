#include <iostream>

using namespace std;

const int MAX = 20;

int main()
{
	int totalbed,freebed,departguest;
	int guest[MAX];
	char c;
	int n,j;

	inline void init(int * a);

	while(cin>>totalbed , totalbed != 0)
	{
		freebed = totalbed;
		departguest = 0;
		init(guest);
		getchar();
		while((c = getchar()) != '\n')
		{
			n = c - 'A' + 1;
			for(j = 0;j<MAX;j++)
			{
				if(guest[j] == n)//������ȥ
				{
					freebed++;
					guest[j] = 0;
					break;
				}
			}
			if(j >= MAX)//���˵���
			{
				if(freebed > 0)
				{
					for(int j = 0;j<MAX;j++)
					{
						if(guest[j] == 0)
						{
							guest[j] = n;
							freebed--;
							break;
						}
					}
				}
				else
				{
					getchar();//����û�п�λ����ȥ
					departguest++;
				}
			}
		}
		if(departguest == 0)
			cout<<"All customers tanned successfully."<<endl;
		else
			cout<<departguest<<" customer(s) walked away."<<endl;
	}

	return 0;
}

void init(int * a)
{
	for(int i = 0;i<MAX;i++)
		a[i] = 0;
}