#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

class problem
{
    public:
        bool operator<(const problem& other) const
        {
            return this->growth < other.growth;
        }
        int level, growth;
};

bool cmpByLevel(const problem& a, const problem& b)
{
    return a.level < b.level;
}

problem problems[100001];

int main()
{
    int n, m, p;
    int a, b;
    int i, j;
    while(scanf("%d %d %d", &n, &m, &p) != EOF)
    {
        priority_queue<problem> solvable;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            problems[i].level = a;
            problems[i].growth = b;
        }
        sort(problems, problems + n, cmpByLevel);
        j = 0;
        for(i = 0; i < m; i++)
        {
            for(; j < n; j++)
            {
                if(problems[j].level <= p)
                    solvable.push(problems[j]);
                else
                    break;
            }
            if(!solvable.empty())
            {
                problem choice = solvable.top();
                solvable.pop();
                p += choice.growth;
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
