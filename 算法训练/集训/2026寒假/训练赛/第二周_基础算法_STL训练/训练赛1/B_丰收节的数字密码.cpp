#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for(long i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        
    }

    sort(s.begin(), s.end(), [](const string& a, const string& b) {
        return a + b > b + a;  
    });

    for(const string& num : s)
    {
        cout << num;
    }

    cout << endl;

    return 0;
}