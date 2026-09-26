#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A[3], B[3], C[3], C2[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> C[i];
        C2[i] = C[i] * 2;
    }

    for (int i = 0; i < 3; i++)
    {
        A[i] = 1;
        B[i] = -1;

        while (A[i] + B[i] != C2[i])
        {
            if (A[i] + B[i] > C2[i])
            {
                A[i]--;
                //    continue;
            }
            else if (A[i] + B[i] < C2[i])
            {
                A[i]++;
                //    continue;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        while (A[i] > 10 || B[i] < -10)
        {
            A[i]--;
            B[i]++;
        }
        if (A[i] == C[i] || B[i] == C[i])
        {
            A[i]++;
            B[i]--;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << A[i] << ' ';
    }
    for (int i = 0; i < 3; i++)
    {
        cout << B[i] << ' ';
    }

    return 0;
}