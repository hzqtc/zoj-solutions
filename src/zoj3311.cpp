#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int i, len;
    while(cin >> str)
    {
        len = str.length();
        int z = 0, j = 0, o0 = 0, o1 = 0, o2 = 0;
        int zindex, jindex;
        for(i = 0; i < len; i++)
        {
            char c = str[i];
            switch(c)
            {
                case 'Z':
                    z++;
                    zindex = i;
                    break;
                case 'O':
                    if(j > 0)
                        o2++;
                    else if(z > 0)
                        o1++;
                    else
                        o0++;
                    break;
                case 'J':
                    j++;
                    jindex = i;
                    break;
                default:
                    break;
            }
        }
        if(z == 1 && j == 1 && zindex < jindex && o1 > 0 && o2 > 0 && o0 + o1 == o2)
            cout << "Accepted" << endl;
        else
            cout << "Wrong Answer" << endl;
    }
    return 0;
}
