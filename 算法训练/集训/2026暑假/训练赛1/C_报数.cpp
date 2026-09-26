#include <iostream>
using namespace std;

int main()
{
    long long n = 0;
    cin >> n;
    int p = 0, q = 0;
    cin >> p >> q;

    for (int i = 1; i <= n; i++)
    {
        if (i % p == 0 && i % q == 0)
        {
            cout << i << endl;
        }
        else if (i % p == 0)
        {
            continue;
        }
        else if (i % q == 0)
        {
            continue;
        }
        else
        {
            cout << i << endl;
        }
    }
}