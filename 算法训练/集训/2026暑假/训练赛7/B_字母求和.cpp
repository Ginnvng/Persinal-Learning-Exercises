#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n = 0;
    cin >> n;
    string s = "";
    cin >> s;

    long num = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            num += (int)s[i] - 'a' + 1;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            num += (int)s[i] * -1;
        }
    }

    cout << num << '\n';
}