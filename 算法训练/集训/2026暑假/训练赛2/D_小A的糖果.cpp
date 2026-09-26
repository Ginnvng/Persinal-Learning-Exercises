#include <iostream>
#include <vector>
using namespace std;

int main()
{

    long long n = 0, x = 0;
    cin >> n >> x;

    vector<long long> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    long long count = 0;
    for (int i = 1; i < n; i++)
    {
        long long sum = A[i - 1] + A[i];
        if (sum > x)
        {
            A[i] -= (sum - x);
            if (A[i] < 0)
            {
                A[i - 1] -= (A[i] * -1);
                A[i] += (A[i] * -1);
            }
            count += (sum - x);
        }
    }
    cout << count << endl;
}