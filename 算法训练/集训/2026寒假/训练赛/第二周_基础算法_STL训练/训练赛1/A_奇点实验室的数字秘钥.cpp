#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> num(n);
    string s;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> num[i].first;
        s = to_string(num[i].first);
        num[i].second = (int)s[0]-'0';
        size_t len = s.size() - 1 ;
        while(len > 0)    
        {   
            num[i].second += (int)s[len]-'0';
            len--;
        }
    }   

    sort(num.begin(),num.end(),[](const pair<int,int> &a,const pair<int,int> &b)
    {
        if(a.second !=b.second)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first < b.first;
        }
    });

    for(int i = 0 ; i < n ; i++)
    {
        cout << num[i].first << " ";
    }
    cout << "\n";
    return 0;
}