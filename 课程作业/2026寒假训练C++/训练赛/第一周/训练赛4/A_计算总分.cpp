#include <iostream>
#include <string>
using namespace std;
#define N 999999

struct Students
{
    string num;
    string name;
    int c;
    int m;
    int e;
    int sum;
};


int main()
{   
    int n;
    cin >> n;
    Students StuArray[N];
    for(int i = 0 ; i < n ; i++ )
    {
        cin >> StuArray[i].num >> StuArray[i].name >> StuArray[i].c >> StuArray[i].m >> StuArray[i].e;
        StuArray[i].sum = StuArray[i].c + StuArray[i].e + StuArray[i].m;
        cout << StuArray[i].sum << '\n';
    }
    return 0;
}