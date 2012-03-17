#include <cstdio>

using namespace std;

struct cube
{
	int a,b,c,d;
};


int main()
{
	const int MAX = 200;
	cube temp;
	
	for(temp.a=6;temp.a<=MAX;temp.a++)
	{
		for(temp.b=2;temp.b<temp.a;temp.b++)
		{
			for(temp.c=temp.b;temp.c<temp.a;temp.c++)
			{
				for(temp.d=temp.c;temp.d<temp.a;temp.d++)
				{
					if(temp.b * temp.b * temp.b + temp.c * temp.c * temp.c + temp.d * temp.d * temp.d == temp.a * temp.a * temp.a)
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n",temp.a,temp.b,temp.c,temp.d);
					}
				}
			}
		}
	}

	return 0;
}

