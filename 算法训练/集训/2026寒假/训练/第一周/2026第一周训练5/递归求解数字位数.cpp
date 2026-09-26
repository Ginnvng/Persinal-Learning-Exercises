#include <iostream>
using namespace std;

int f(int s, int n)
{
    if (s)
    {
        s /= 10;
        return f(s, n + 1);
    }
    else
    {
        return n;
    }
}

int main()
{
    int s;
    cin >> s;
    cout << f(s, 0) << endl;
}