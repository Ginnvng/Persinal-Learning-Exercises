#include <iostream>
using namespace std;

int F(int a, int b, int i, int n)
{
    if (i == n)
    {
        return a;
    }
    else
    {
        return F(b, a + b, i + 1, n);
    }
}

int main()
{
    int f1 = 0, f2 = 1;
    int n;
    cin >> n;
    cout << F(f1, f2, 0, n) << endl;
}