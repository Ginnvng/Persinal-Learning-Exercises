#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 0;
    int X = 0;
    int num = 0;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++)
    {

        cin >> a[i];
    }

    cin >> X;

    for (int i = 0; i < N; i++)
    {
        if (a[i] <= X)
        {
            X -= a[i];
            num++;
        }
    }

    cout << num << '\n';
}