#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct
{
    int weight;
    int u, v;
} edge;

int cmpEdgeWeight(const void* a, const void* b)
{
    edge* e1 = (edge*)a;
    edge* e2 = (edge*)b;
    if(e1->weight != e2->weight)
        return e1->weight - e2->weight;
    else if(e1->u != e2->u)
        return e1->u - e2->u;
    else
        return e1->v - e2->v;
}

int cmpEdgeLexico(const void* a, const void* b)
{
    edge* e1 = (edge*)a;
    edge* e2 = (edge*)b;
    if(e1->u != e2->u)
        return e1->u - e2->u;
    else
        return e1->v - e2->v;
}

int find(int* set, int i)
{
    while(i != set[i])
        i = set[i];
    return i;
}

int main()
{
    int t;
    int n;
    int i, j;

    const int MAX = 128;
    int vertex[MAX];
    edge edges[MAX * MAX];
    edge trees[MAX];
    int edgeCount, treeCount;

    cin >> t;
    while(t--)
    {
        cin >> n;
        int w;
        edgeCount = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                cin >> w;
                if(j > i && w > 0)
                {
                    edges[edgeCount].weight = w;
                    edges[edgeCount].u = i;
                    edges[edgeCount].v = j;
                    edgeCount++;
                }
            }
        }

        qsort(edges, edgeCount, sizeof(edge), cmpEdgeWeight);
        for(i = 1; i <= n; i++)
            vertex[i] = i;
        treeCount = 0;
        for(i = 0; i < edgeCount; i++)
        {
            int a = find(vertex, edges[i].u);
            int b = find(vertex, edges[i].v);
            if(a != b)
            {
                vertex[a] = b;
                trees[treeCount] = edges[i];
                treeCount++;
            }
        }
        if(treeCount == n -1)
        {
            qsort(trees, treeCount, sizeof(edge), cmpEdgeLexico);
            for(i = 0; i < treeCount; i++)
            {
                if(i > 0)
                    cout << ' ';
                cout << trees[i].u << ' ' << trees[i].v;
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
