#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int carry = 0;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    string sum;
    sum.reserve(max(a.size(), b.size()) + 1);

    while (i >= 0 || j >= 0 || carry)
    {
        int s = carry;
        if (i >= 0) s += a[i--] - '0';
        if (j >= 0) s += b[j--] - '0';
        sum.push_back('0' + (s % 10));
        carry = s / 10;
    }

    reverse(sum.begin(), sum.end());
    cout << sum << endl;
    return 0;
}