#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> word(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> word[i];
    }

    sort(word.begin(), word.end(), [](const auto &a, const auto &b)
         {
        if(a.size() != b.size())
        {
            return a.size() < b.size();
        }
        else
        {
            return a < b;
        } });

    for (int i = 0; i < N; ++i)
    {
        cout << word[i] << "\n";
    }
}