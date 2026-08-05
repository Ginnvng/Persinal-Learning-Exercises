#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n = 0;
    vector<vector<string>> S = {{".....", "****.", ".....", "....."},
                                {".***.", "****.", "****.", "****."},
                                {".***.", "****.", ".....", "....."},
                                {".***.", "****.", ".****", "****."},
                                {".....", "****.", ".....", "....."}};
    cin >> n;

    string s = to_string(n);
    long a = s.length();

    for (int i = 0; i < 5; i++)
    {
        for (long j = 0; j < a; j++)
        {
            cout << S[i][s[j] - '0'];
        }
        cout << '\n';
    }
}