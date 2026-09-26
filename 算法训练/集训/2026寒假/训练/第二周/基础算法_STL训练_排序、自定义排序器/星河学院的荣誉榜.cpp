#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    struct File
    {
        string Name;
        int Score;
        int ID;
    };

    vector<File> file(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> file[i].Name >> file[i].Score >> file[i].ID;
    }

    sort(file.begin(), file.end(), [](const auto &a, const auto &b)
         {
        if(a.Score != b.Score)
        {
            return a.Score > b.Score;
        }
        else
        {
            return a.ID < b.ID;
        } });

    for (int i = 0; i < N; ++i)
    {
        cout << file[i].Name << ' ' << file[i].Score << ' ' << file[i].ID << "\n";
    }
}