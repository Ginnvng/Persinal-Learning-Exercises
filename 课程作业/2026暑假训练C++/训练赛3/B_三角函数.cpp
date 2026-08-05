#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;

    long long min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }

    long long max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }

    for (long long i = min; i > 1; i--)
    {
        if (max % i == 0 && min % i == 0)
        {
            max /= i;
            min /= i;
        }
    }

    cout << min << '/' << max << '\n';
}