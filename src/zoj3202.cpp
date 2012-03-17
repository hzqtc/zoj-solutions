#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int index = 0, max = 0, secondmax = 0;
        int c;
        for(int i = 0; i < n; i++)
        {
            cin >> c;
            if(c > max)
            {
                secondmax = max;
                max = c;
                index = i + 1;
            }
            else if(c > secondmax)
            {
                secondmax = c;
            }
        }
        cout << index << ' ' << secondmax << endl;
    }
    return 0;
}
