#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ST
{
    string s;
    int a;
};

const int N = 100010;

int main()
{
    ST stu[N];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].s >> stu[i].a;
        cout << stu[i].s << " " << stu[i].a << endl;
    }
}
