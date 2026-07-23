#include <iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;
    if(n%7 == 0 && n <= 10000 && n >= 0)
    {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}