#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    char strL = 'A';

    for (int i = 0; i < n; i++)
    {
        if (strL > 'Z')
        {
            strL -= 26;
        }

        char strH = strL;

        for (int j = 0; j < n; j++)
        {
            if (strH > 'Z')
            {
                strH -= 26;
            }
            cout << strH;
            strH += 1;
        }

        strL += 1;
        cout << '\n';
    }
}