#include <bits/stdc++.h>
using namespace std;

int dp[30][30];
bool ctrl[30][30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;

    dp[0][0] = 1;

    int dx[] = {0, -2, -2, -1, 1, 2, 2, 1, -1};
    int dy[] = {0, -1, 1, 2, 2, 1, -1, -2, -2};
    for (int k = 0; k < 9; k++)
    {
        int x = hx + dx[k];
        int y = hy + dy[k];
        if (x >= 0 && x <= n && y >= 0 && y <= m)
            ctrl[x][y] = true;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (ctrl[i][j])
            {
                dp[i][j] = 0;
                continue;
            }

            long long fromup = (i > 0) ? dp[i - 1][j] : 0;
            long long fromleft = (j > 0) ? dp[i][j - 1] : 0;
            dp[i][j] = fromup + fromleft;
        }
    }

    cout << dp[n][m] << '\n';
}