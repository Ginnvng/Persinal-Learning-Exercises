#include <iostream>
using namespace std;

int main()
{
    char s;
    cin >> s;
    for (int i = 0; i < 3; i++)
    {
        int j = 2 - i;

        int a = i, b = j;
        while (b--)
        {
            cout << ' ';
        }

        while (a--)
        {
            cout << s;
        }

        a = i;
        b = j;

        cout << s;

        while (a--)
        {
            cout << s;
        }

        cout << '\n';
    }
}