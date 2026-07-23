#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> time(n);

    for (int i = 0; i < n; i++)
    {
        cin >> time[i].first >> time[i].second;
    }

    sort(time.begin(), time.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if(a.second != b.second)
        {
            return a.second < b.second;
        } 
        else
        {
            return a.first > b.first;
        } });

    long long sum_time = 0;

    for (int i = 0; i < n; i++)
    {
        sum_time += time[i].first;
        if (sum_time > time[i].second)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}