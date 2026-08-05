#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result = "";
    int carry = 0;
    int i = 0;

    while (i < (int)a.size() || i < (int)b.size() || carry != 0)
    {
        int digitA = 0;
        if (i < (int)a.size())
        {
            digitA = a[i] - '0';
        }

        int digitB = 0;
        if (i < (int)b.size())
        {
            digitB = b[i] - '0';
        }

        int sum = digitA + digitB + carry;
        int currentDigit = sum % 10;
        carry = sum / 10;

        result.push_back('0' + currentDigit);
        i++;
    }

    reverse(result.begin(), result.end());
    cout << "计算结果：" << result << endl;

    return 0;
}
