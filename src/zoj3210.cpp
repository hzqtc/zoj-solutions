#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        stack<int> s;
        queue<int> q;
        bool isstack = true, isqueue = true;
        int num;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> num;
            s.push(num);
            q.push(num);
        }
        for(int i = 0; i < n; i++)
        {
            cin >> num;
            if(s.top() != num)
                isstack = false;
            if(q.front() != num)
                isqueue = false;
            s.pop();
            q.pop();
        }
        if(isstack && isqueue)
            cout << "both" << endl;
        else if(isstack)
            cout << "stack" << endl;
        else if(isqueue)
            cout << "queue" << endl;
        else
            cout << "neither" << endl;
    }
    return 0;
}
