#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_pal(string s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }

        l++;
        r--;
    }

    return true;
}

int main()
{
    string S1;
    cin >> S1;

    int pos = 0;
    int n = (int)S1.size();

    for (int i = 0; i < n; ++i)
    {
        if (is_pal(S1, i, n - 1))
        {
            pos = i;
            break;
        }

    }

    string add = S1.substr(0, pos);
    reverse(add.begin(), add.end());
    S1 += add;
    cout << S1 << endl;

}