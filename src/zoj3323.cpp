#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    string line;
    cin >> t;
    getline(cin, line);
    while(t--)
    {
        getline(cin, line);
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] >= '0' && line[i] <= '9')
                ;
            else
                cout << line[i];
        }
        cout << endl;
    }
    return 0;
}
