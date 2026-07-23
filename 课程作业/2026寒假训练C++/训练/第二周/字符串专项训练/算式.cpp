#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    size_t pos = s.find("+");
    if (pos != string::npos)
    {
        int a = stoi(s.substr(0, pos));
        int b = stoi(s.substr(pos + 1));
        cout << (a + b) << endl;
    }
    else
    {
        pos = s.find("-");
        if (pos != string::npos)
        {
            int a = stoi(s.substr(0, pos));
            int b = stoi(s.substr(pos + 1));
            cout << (a - b) << endl;
        }
        else
        {
            cout << stoi(s) << endl;
        }
    }
}