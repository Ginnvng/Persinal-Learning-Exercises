#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0, op = 0;
    long long x = 0;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> q;

    for (int i = 0; i < n; i++)
    {
        cin >> op;
        switch (op)
        {
            case 1:
                cin >> x;
                q.push(x);
                break;
            case 2:
                cout << q.top() << '\n';
                break;
            case 3:
                q.pop();
                break;
        }
    }
}