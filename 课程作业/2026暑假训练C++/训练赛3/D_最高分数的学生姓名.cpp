#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int score;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;
    cin >> N;

    vector<Student> stu(N);

    for (int i = 0; i < N; i++)
    {
        cin >> stu[i].score >> stu[i].name;
    }

    sort(stu.begin(), stu.end(),
         [](const Student &a, const Student &b) { return a.score > b.score; });

    cout << stu[0].name << '\n';
}