#include <bits/stdc++.h>
using namespace std;

int n = 0;
long long s = 1, ku = 0;
vector<long long> S(n), KU(n);
long long low = 99999999;
long long num = 0;
int cnt = 0;
void findfood(int index)
{

    if (index == n)
    {
        if (cnt > 0)
        {
            num = s - ku;
            if (num < 0)
            {
                num *= -1;
            }

            if (num < low)
            {
                low = num;
            }
        }
        return;
    }

    findfood(index + 1);
    s *= S[index];
    ku += KU[index];
    cnt++;
    findfood(index + 1);
    s /= S[index];
    ku -= KU[index];
    cnt--;
}

int main()
{
    cin >> n;

    S.resize(n);
    KU.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> S[i] >> KU[i];
    }

    findfood(0);

    cout << low << '\n';
}