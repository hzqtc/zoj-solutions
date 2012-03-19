#include <iostream>

using namespace std;

class date
{
public:
    date(int y, int m, int d)
    {
        this->value = y * 10000 + m * 100 + d;
    }

    bool operator<(const date& other) const
    {
        return this->value < other.value;
    }

private:
    int value;
};

int main()
{
    int n;
    int y, m, d;
    cin >> n;
    while(n--)
    {
        cin >> y >> m >> d;
        date javaman(y, m, d);
        cin >> y >> m >> d;
        date cpcs(y, m, d);

        if(javaman < cpcs)
            cout << "javaman" << endl;
        else if(cpcs < javaman)
            cout << "cpcs" << endl;
        else
            cout << "same" << endl;
    }
    return 0;
}
