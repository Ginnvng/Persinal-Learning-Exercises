#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t; // 测试用例
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n, q;
        int x, y, z;
        cin >> n >> q;

        vector<int> energy(n); // 初始能量值
        for (int i = 0; i < n; i++)
        {
            cin >> energy[i];
        }

        for (int i = 0; i < q; i++)
        {

            cin >> x >> y >> z;
            for (int j = x - 1; j < y; j++)
            {
                energy[j] += z;
            }
        }

        sort(energy.begin(), energy.end());
        cout << energy[0] << endl;
    }
}