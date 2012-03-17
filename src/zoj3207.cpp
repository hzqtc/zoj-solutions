#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n, k;
    set<string> common;
    string token;
    cin >> n;
    while(n--)
    {
        cin >> token;
        common.insert(token);
    }
    cin >> k;
    while(k--)
    {
        int p, c = 0;
        cin >> p;
        while(p--)
        {
            cin >> token;
            if(common.find(token) != common.end())
                c++;
        }
        cout << c << endl;
    }
    return 0;
}
