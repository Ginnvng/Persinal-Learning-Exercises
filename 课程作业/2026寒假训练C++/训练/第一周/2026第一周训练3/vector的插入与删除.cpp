#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;
    int op, pos;

    for (int i = 0; i < k; i++)
    {
        cin >> op >> pos;
        if (op == 1)
        {
            int x;
            cin >> x;
            arr.insert(arr.begin() + pos, x);
        }
        else if (op == 0)
        {
            arr.erase(arr.begin() + pos);
        }
    }

    for (int i : arr)
    {
        cout << i << " ";
    }
}