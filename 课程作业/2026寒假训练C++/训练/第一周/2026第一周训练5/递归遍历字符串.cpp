#include <iostream>
#include <string>
using namespace std;

void print(string s, int i)
{
    if (i == s.size())
    {
        return;
    }
    else
    {
        cout << s[i];
        print(s, i + 1);
    }
}

int main()
{
    string s;
    getline(cin, s);
    print(s, 0);
}
