#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        int count = 1;

        int j = i;
        while (j--)
        {

            sum += count;
            count++;
        }
    }

    cout << sum << endl;
}