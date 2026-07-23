#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    size_t pos = s1.find(s2);

    if (pos != string::npos)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}