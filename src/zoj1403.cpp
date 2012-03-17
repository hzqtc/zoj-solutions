#include <iostream>
#include <cstdlib>

#define CTOI(c) (int)(c - 'A' + 1)
#define ITOC(i) (char)(i - 1 + 'A')

using namespace std;

int cmp(const void * a,const void * b);

int main()
{
    int target;
    const int MAX = 16;
    int letter[MAX],count;;
    char c;
    int i1,i2,i3,i4,i5;
    int ok[5];

    while(cin>>target , target != 0)
    {
		count = 0;
		ok[0] = ok[1] = ok[2] = ok[3] = ok[4] = 0;
		getchar();
		while((c = getchar()) != '\n')
		{
			letter[count++] = CTOI(c);
		}
		qsort(letter,count,sizeof(int),cmp);
		for(i1=0;i1<count;i1++)
		{
			for(i2=0;i2<count;i2++)
			{
				if(i2 == i1)
					continue;
				for(i3=0;i3<count;i3++)
				{
					if(i3 == i2 || i3 == i1)
						continue;
					for(i4=0;i4<count;i4++)
					{
						if(i4 == i3 || i4 == i2 || i4 == i1)
							continue;
						for(i5=0;i5<count;i5++)
						{
							if(i5 == i4 || i5 == i3 || i5 == i2 || i5 == i1)
								continue;
							if(letter[i1] - letter[i2] * letter[i2] + letter[i3] * letter[i3] * letter[i3] - letter[i4] * letter[i4] * letter[i4] * letter[i4] + letter[i5] * letter[i5] * letter[i5] * letter[i5] * letter[i5] == target)
							{
								ok[0] = letter[i1];
								ok[1] = letter[i2];
								ok[2] = letter[i3];
								ok[3] = letter[i4];
								ok[4] = letter[i5];
							}
						}
					}
				}
			}
		}
		if(ok[0] != 0)
			cout<<ITOC(ok[0])<<ITOC(ok[1])<<ITOC(ok[2])<<ITOC(ok[3])<<ITOC(ok[4])<<endl;
		else
			cout<<"no solution"<<endl;
    }

    return 0;
}

int cmp(const void * a,const void * b)
{
    return *(int *)a - *(int *)b;
}
