#include <bits/stdc++.h>
using namespace std;

struct Good
{
    string name;
    long pride;
    int prio;
};

int main()
{
    long long M;
    int N;

    cin >> M >> N;

    vector<Good> goods(N);

    for (int i = 0; i < N; i++)
    {
        cin >> goods[i].name >> goods[i].pride >> goods[i].prio;
    }

    sort(goods.begin(), goods.end(),
         [](const Good &a, const Good &b)
         {
             if (a.prio != b.prio)
             {
                 return a.prio < b.prio;
             }
             else if (a.pride != b.pride)
             {
                 return a.pride < b.pride;
             }
             else
             {
                 return a.name < b.name;
             }
         });

    vector<string> good;

    for (int i = 0; i < N; i++)
    {
        if (goods[i].pride <= M)
        {
            good.push_back(goods[i].name);
            M -= goods[i].pride;
        }
    }

    sort(good.begin(), good.end(),
         [](const string &a, const string &b) { return a < b; });

    for (string &S : good)
    {
        cout << S << '\n';
    }
}