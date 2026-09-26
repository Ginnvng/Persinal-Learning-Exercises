#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int count = 0;

    for (int i = n; i <= m; i++)
    {
        if (i % 5 == 0)
            count++;
    }

    cout << count << endl;
}