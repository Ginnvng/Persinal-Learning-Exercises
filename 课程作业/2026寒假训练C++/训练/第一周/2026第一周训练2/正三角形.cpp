#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = n - i; j > 0; j--)
        {
            cout << " ";
        }

        for (int a = count; a > 0; a--)
        {
            cout << "*";
        }

        count += 2;

        cout << endl;
    }
}