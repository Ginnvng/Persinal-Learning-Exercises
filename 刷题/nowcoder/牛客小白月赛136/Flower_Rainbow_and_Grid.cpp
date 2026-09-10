#include <bits/stdc++.h>
using namespace std;

void check(long long X, int n, int m, long long &totalcnt, long long &totalsum)
{
    totalcnt = 0;
    totalsum = 0;

    long long j = 0;
    long long j_sum = 0;

    for (long long i = 1; i <= n; i++)
    {
        long long lim = i * i - X;
        while (j < m && (j + 1) * (j + 1) <= lim)
        {
            j++;
            j_sum += j * j;
        }

        totalcnt += j;
        totalsum += i * i * j - j_sum;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long k;
    int T, n, m;
    cin >> T;

    while (T--)
    {
        cin >> n >> m >> k;
        long long low, hi;
        low = 1LL - (long long)m * m;
        hi = (long long)n * n - 1;

        while (low < hi)
        {
            long long mid = low + (hi - low + 1) / 2;
            long long cnt, sum;
            check(mid, n, m, cnt, sum);
            if (cnt >= k)
                low = mid;
            else
                hi = mid - 1;
        }

        long long cnt, sum;
        check(low, n, m, cnt, sum);
        sum -= (cnt - k) * low;
        cout << sum << '\n';
    }
}