#include <bits/stdc++.h>
using namespace std;

struct herb
{
    int T;
    int V;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0;
    cin >> T;
    int M = 0;
    cin >> M;

    vector<herb> herbs(M);

    for (int i = 0; i < M; i++)
    {
        cin >> herbs[i].T >> herbs[i].V;
    }

    vector<int> dp(T + 1);

    for (int i = 0; i < M; i++)
    {
        for (int j = T; j >= 0; --j)
        {
            if (j >= herbs[i].T)
            {
                int maxV = max(dp[j], herbs[i].V + dp[j - herbs[i].T]);
                dp[j] = maxV;
            }
        }
    }
    cout << dp[T] << '\n';
}