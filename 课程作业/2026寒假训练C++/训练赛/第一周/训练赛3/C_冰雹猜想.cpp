#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n << '\n';
    while(n > 1)
    {
        if (n%2 == 0)
        {
            n /= 2;
            cout << n << '\n';
        }
        else
        {
            n *= 3;
            n++;
            cout << n << '\n';
        }
        
    }
    return 0;
}