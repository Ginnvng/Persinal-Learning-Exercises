#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;

    n %= 26;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = char((s[i] - 'a' + n) % 26 + 'a');
    }

    cout << s << endl;
}