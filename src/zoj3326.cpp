#include <iostream>

using namespace std;

const int daysNLeap[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int daysLeap[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int y)
{
    if(y % 100 == 0)
        return y % 400 == 0;
    else
        return y % 4 == 0;
}

bool isPrime(int n)
{
    return (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29 || n == 31);
}

class date
{
    public:
        int y, m, d;

        friend istream& operator>>(istream& in, date& d)
        {
            in >> d.y >> d.m >> d.d;
            return in;
        }

        friend ostream& operator<<(ostream& out, const date& d)
        {
            out << d.y << '-' << d.m << '-' << d.d;
            return out;
        }

        date& nextDay()
        {
            const int* days;
            if(isLeapYear(this->y))
                days = daysLeap;
            else
                days = daysNLeap;

            this->d++;
            if(this->d > days[this->m])
            {
                this->d = 1;
                this->m++;
                if(this->m > 12)
                {
                    this->m = 1;
                    this->y++;
                }
            }
            return *this;
        }

        date& nextMonth()
        {
            this->d = 1;
            this->m++;
            if(this->m > 12)
            {
                this->m = 1;
                this->y++;
            }
            return *this;
        }

        bool operator<=(const date& other) const
        {
            int u = this->y * 10000 + this->m * 100 + this->d;
            int v = other.y * 10000 + other.m * 100 + other.d;
            return u <= v;
        }
};

int main()
{
    int t;
    date d1, d2;
    int count;
    cin >> t;
    while(t--)
    {
        cin >> d1 >> d2;
        count = 0;
        while(d1 <= d2)
        {
            if(!isPrime(d1.m))
            {
                d1.nextMonth();
                continue;
            }
            if(isPrime(d1.d))
                count++;
            d1.nextDay();
        }
        cout << count << endl;
    }
    return 0;
}
