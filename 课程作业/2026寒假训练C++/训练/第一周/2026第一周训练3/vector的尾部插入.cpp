#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    int n;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        arr.push_back(n);
    }

    for (int a : arr)
    {
        cout << a << endl;
    }
}