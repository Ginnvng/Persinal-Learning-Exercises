#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    struct two
    {
        int num;
        int Znum;
    };

    vector<two> Stu(n);
    int N;
    for (int i = 0; i < n; ++i)
    {
        cin >> N;

        Stu[i].num = N;
        if (N < 0)
        {
            Stu[i].Znum = N * (-1);
        }
        else
        {
            Stu[i].Znum = N;
        }
    }

    sort(Stu.begin(), Stu.end(), [](const auto &a, const auto &b)
         {
        if(a.Znum != b.Znum)
        {
            return a.Znum < b.Znum;
        }
        else
        {
            return a.num < b.num;
        } });

    for (int i = 0; i < n; ++i)
    {
        cout << Stu[i].num << " ";
    }
}