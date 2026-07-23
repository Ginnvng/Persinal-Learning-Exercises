#include <iostream>
using namespace std;

long long jiechen(long long n)
{
    if (n == 1 || n <= 0)
    {
        return 1;
    }
    else
    {
        return jiechen(n - 1) * n;
    }
}

int main()
{
    long long n;
    cin >> n;
    cout << jiechen(n) << endl;
}