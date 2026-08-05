#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    long long n = 0;
    cin >> n;
    long long x = pow(n, 1.0 / 5);
    if (pow(x, 5) == n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
