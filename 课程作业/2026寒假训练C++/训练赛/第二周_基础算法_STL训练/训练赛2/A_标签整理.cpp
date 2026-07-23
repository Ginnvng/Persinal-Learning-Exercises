#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> s(N);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> s[i];
    }

    sort(s.begin(),s.end(),[](const string&a,const string &b)
    {
        if(a.size() != b.size())
        {
            return a.size() < b.size();
        }
        else if(a != b)
        {
            return a < b;
        }
        else
        {  
            return a == b;
        }
    });

    s.erase(unique(s.begin(),s.end()),s.end());

    for(string &S : s)
    {
        cout << S << "\n";
    }
}