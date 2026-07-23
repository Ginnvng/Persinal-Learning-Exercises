#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int b : a)
    {
        cout << b;
    }
}