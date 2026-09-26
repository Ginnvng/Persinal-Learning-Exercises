#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    size_t pos, len;
    for (int i = 0; i < n; i++)
    {
        cin >> pos >> len;
        if (pos < 0 || pos > s.size() - 1 || len < 1 || len > s.size() - pos)
        {
            cout << "error" << endl;
            return 0;
        }

        cout << s.substr(pos, len) << endl;
    }
}