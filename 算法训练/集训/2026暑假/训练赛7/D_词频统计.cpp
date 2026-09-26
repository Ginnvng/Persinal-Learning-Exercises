#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<string> S(n);
    map<string, int> word;

    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
        for (char &ch : S[i])
        {
            ch = tolower(ch);
        }

        word[S[i]]++;
    }

    vector<pair<string, int>> wordnum(word.begin(), word.end());

    sort(wordnum.begin(), wordnum.end(),
         [](const pair<string, int> &a, const pair<string, int> &b)
         { return a.second > b.second; });

    cout << wordnum[0].first << '\n';
}