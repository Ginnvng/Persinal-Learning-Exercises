#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr = {0, 1};

    for (int i = 2; i <= n; i++)
    {
        arr.push_back(arr[i - 1] + arr[i - 2]);
    }

    cout << arr[n] << endl;
}