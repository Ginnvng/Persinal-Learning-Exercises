#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int a = y - x;

    if (a >= 0)
    {
        cout << x << endl;
    }
    else
    {
        int b = a * (-1);

        if (b <= 100)
        {
            cout << b + y << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
}