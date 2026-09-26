#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    map<string, int> grades;
    string take;
    string name;
    int score;
    int times = 0;
    cin >> times;
    while (times--)
    {
        cin >> take;
        if (take == "add" || take == "update")
        {
            cin >> name >> score;
            grades[name] = score;
        }
        else if (take == "query")
        {
            cin >> name;
            auto it = grades.find(name);
            if (it != grades.end())
            {
                cout << it->second << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else if (take == "remove")
        {
            cin >> name;
            grades.erase(name);
        }
        else if (take == "top")
        {
            int k;
            cin >> k;
            vector<pair<string, int>> v;
            for (const auto &p : grades)
            {
                v.push_back(p);
            }
            sort(v.begin(), v.end(), [](const auto &a, const auto &b)
                 {
                if (a.second != b.second) {
                    return a.second > b.second;
                }
                    return a.first < b.first; });

            for (int i = 0; i < k; i++)
            {
                cout << v[i].first << " " << v[i].second << "\n";
            }
        }
        else if (take == "count")
        {
            cout << grades.size() << endl;
        }
    }
    return 0;
}