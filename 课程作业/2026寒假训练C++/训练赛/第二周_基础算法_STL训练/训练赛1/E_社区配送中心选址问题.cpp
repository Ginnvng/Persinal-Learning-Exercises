#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> people(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> people[i];
    }

    sort(people.begin(), people.end());

    int a = people.size();

    if (a % 2 != 0)
    {
        a = (a - 1) / 2;
    }
    else
    {
        a /= 2;
    }

    long long sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += abs(people[i] - people[a]);
    }

    cout << sum << endl;
}