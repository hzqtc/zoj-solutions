#include <iostream>
#include <cstring>

using namespace std;

int find(int* set, int i)
{
    if(set[i] != i)
        return set[i] = find(set, set[i]);
    else
        return i;
}

void join(int* set, int a, int b)
{
    int ra = find(set, a);
    int rb = find(set, b);
    if(ra != rb)
        set[b] = a;
}

int main()
{
    int n, m;
    int degree[16];
    int nodeset[16];
    int a, b, i;
    while(cin >> n >> m)
    {
        memset(degree, 0, sizeof(degree));
        memset(nodeset, 0, sizeof(nodeset));
        for(i = 1; i <= n; i++)
            nodeset[i] = i;

        for(i = 0; i < m; i++)
        {
            cin >> a >> b;
            degree[a]++;
            degree[b]++;
            join(nodeset, a, b);
        }
        if(n < 3 || n != m)
        {
            cout << "NO" << endl;
            continue;
        }
        for(i = 1; i <= n; i++)
        {
            if(degree[i] != 2 || find(nodeset, i) != find(nodeset, 1))
                break;
        }
        if(i > n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
