#include <bits/stdc++.h>
using namespace std;

bool ishot(string s1, string s2, int n, int m);

int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;

        if (ishot(s1, s2, n, m))
        {
            cout << "Yes" << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }
}

bool ishot(string s1, string s2, int n, int m)
{
    int front = 0, behind = 0;

    if (n > m)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
        {
            front++;
        }
        else
        {
            break;
        }
    }

    for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; --i, --j)
    {
        if (s1[j] == s2[i])
        {
            behind++;
        }
        else
        {
            break;
        }
    }

    if ((front + behind) >= n)
    {
        return true;
    }
    else
    {
        return false;
    }
}