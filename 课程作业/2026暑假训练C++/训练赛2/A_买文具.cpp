#include <iostream>
using namespace std;

int main()
{
    int X, Y, Z;
    long long Q = 0;
    cin >> X >> Y >> Z >> Q;
    long long sum = (2 * X) + (5 * Y) + (3 * Z);
    if (sum <= Q)
    {
        cout << "Yes" << endl;
        cout << Q - sum << endl;
    }
    else
    {
        cout << "No" << endl;
        cout << sum - Q << endl;
    }
}