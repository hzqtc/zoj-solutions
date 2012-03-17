#include <iostream>
#include <cstring>

using namespace std;

int main()
{
        const int MAX = 80;
	char plain[MAX],sub[MAX];
	char c;
        int index;

        cin.getline(plain,MAX,'\n');
        cin.getline(sub,MAX,'\n');
        cout<<sub<<'\n'<<plain<<'\n';
        while((c = getchar()) != EOF)
        {
                for(index=0;index<strlen(plain);index++)
                {
                        if(plain[index] == c)
                        {
                                cout<<sub[index];
                                break;
                        }
                }
                if(index >= strlen(plain))
                {
                        cout<<c;
                }
        }

        return 0;
}
