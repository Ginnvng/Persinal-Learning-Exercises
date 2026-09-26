#include <bits/stdc++.h>
using namespace std;

long long UseMoney(int a, int p, int &k, int buyn)
{
    long long money = 0;
    while (a > 0)
    {
        if (a >= buyn + 1)
        {
            if (k > 0)
            {
                money += p * buyn;
                k--;
            }
            else
            {
                money += p * (buyn + 1);
            }

            a -= buyn + 1;
        }
        else
        {
            money += p * a;
            a = 0;
        }
    }

    return money;
}

int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, m, x, y, k;
        cin >> n >> m >> x >> y >> k;

        long long money = 0;

        if (x >= y)
        {
            money += UseMoney(n, x, k, 2);
            money += UseMoney(m, y, k, 3);
        }
        else
        {
            money += UseMoney(m, y, k, 3);
            money += UseMoney(n, x, k, 2);
        }

        cout << money << '\n';
    }

    return 0;
}