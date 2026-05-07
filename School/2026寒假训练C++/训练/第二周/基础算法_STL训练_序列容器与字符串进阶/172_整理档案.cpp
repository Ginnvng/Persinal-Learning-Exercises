#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> V(n, vector<int>());

    while (m)
    {
        int take = 0;
        cin >> take;
        switch (take)
        {
        case 1:
        {
            int x, v;
            cin >> x >> v;
            x -= 1;
            V[x].push_back(v);
            break;
        }
        case 2:
        {
            int x, y;
            cin >> x >> y;
            x -= 1;
            y -= 1;

            int i = (int)V[x].size();

            if (i <= y)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << V[x][y] << endl;
            }
            break;
        }
        }
        --m;
    }
}