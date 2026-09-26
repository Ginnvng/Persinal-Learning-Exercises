#include <iostream>
#include <string>
using namespace std;

int fun(int n);

int main()
{
    int n;
    cin >> n;
    if (n >= 0)
        cout << fun(n) << '\n';

    else if (n < 0)
        cout << fun(n) * (-1) << '\n';
}

int fun(int n)
{
    int weishu = 0, a;
    a = n;
    while (a > 0)
    {
        a /= 10;
        weishu++;
    }
    string s = 0;
    for (int i = 1; i <= weishu; i++)
    {
        s += n % 10 * i;
    }
    int S = stoi(s);
    return S;
}