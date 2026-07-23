#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> num(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < m; i++)
    {
        int down;
        cin >> down;
        cout << num[down] << endl;
    }
}