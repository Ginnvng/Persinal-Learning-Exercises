#include <bits/stdc++.h>
using namespace std;

int T = 0;
int M = 0;
vector<int> Time(M), V(M);
long sumT = 0;
long sumV = 0;
long endV = 0;
void findherbs(int index)
{
    if (sumT > T)
    {
        return;
    }
    if (index == M)
    {
        if (endV < sumV)
        {
            endV = sumV;
        }
        return;
    }

    findherbs(index + 1);

    sumT += Time[index];
    sumV += V[index];
    findherbs(index + 1);
    sumT -= Time[index];
    sumV -= V[index];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T >> M;
    Time.resize(M);
    V.resize(M);

    for (int i = 0; i < M; i++)
    {
        cin >> Time[i] >> V[i];
    }

    findherbs(0);

    cout << endV << '\n';
}