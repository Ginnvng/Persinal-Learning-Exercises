#include <iostream>
#include <string>
using namespace std;

int main()
{
    int K;
    string S;
    cin >> K >> S;

    int count = 0;
    int max_count = 0;
    int max_pos = 0;

    for (int i = 0; i < K; ++i)
    {
        if (S[i] == 'A')
        {
            count++;
        }
    }

    max_count = count;
    int n = (int)S.size();

    for (int i = K; i < n; ++i)
    {
        if (S[i] == 'A') count++;
        if (S[i - K] == 'A') count--;

        if (max_count < count)
        {
            max_count = count;
            max_pos = i - K + 1;
        }
    }

    if (count == 0)
    {
        return 0;
    }

    cout << S.substr(max_pos, K) << endl;

}