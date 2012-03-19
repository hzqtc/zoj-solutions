#include <iostream>

using namespace std;

int abs(int x)
{
    return x >= 0? x: -x;
}

int main()
{
    int n;
    int p, a, b;
    cin >> n;
    while(n--)
    {
        cin >> p >> a >> b;
        if(abs(p - a) > abs(p - b))
            cout << "B" << endl;
        else
            cout << "A" << endl;
    }
    return 0;
}
