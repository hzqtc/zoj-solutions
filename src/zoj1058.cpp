#include <iostream>
#include <iomanip>

using namespace std;

double format(double& a);

int main()
{
    double rate[5][5];
    int casecount,caseindex;
    const int MAX = 16;
    int countrycount,country[MAX];
    int i,j;
    double money;

    cin>>casecount;
    for(caseindex=0;caseindex<casecount;caseindex++)
    {
        if(caseindex > 0)
            cout<<endl;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                cin>>rate[i][j];
            }
        }
        while(cin>>countrycount , countrycount != 0)
        {
            for(i=0;i<countrycount;i++)
            {
                cin>>country[i];
            }
            cin>>money;
            money *= rate[0][country[0] - 1];
            format(money);
            for(i=0;i<countrycount-1;i++)
            {
                money *= rate[country[i] - 1][country[i + 1] - 1];
                format(money);
            }
            money *= rate[country[countrycount - 1] - 1][0];
            format(money);
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<money<<endl;
        }
    }

    return 0;
}

double format(double& a)
{
    int m = (int)(a * 100);
    int n = (int)(a * 1000) % 10;
    a = (double)m / 100;
    if(n >= 5)
        a += 0.01;
    return a;
}

