#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool length(string s)
{
    return (s.size() > 6);
}

bool upper(string s)
{
    for(char i : s)
    {
        if(i <= 90 && i >= 65)
        {
            return true;
        }
    }
    return false;
}

bool lower(string s)
{
    for(char i : s)
    {
        if(i >= 97 && i <= 122)
        {
            return true;
        }
        
    }
    return false;
}

bool misc(string s)
{
    for(char i : s)
    {
        if(i == 64 || i == 95 || i == 35)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
     vector<string> s;
    //string s;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {   
        string temp;
        cin >> temp;
        s.push_back(temp);

        //cin >> s;

        if(length(s[i]) && upper(s[i]) && lower(s[i]) && misc(s[i]))
        //if(length(s) && upper(s) && lower(s) && misc(s))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
