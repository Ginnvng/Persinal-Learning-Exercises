#include <bits/stdc++.h>
using namespace std;

int WeiShu(long long sum)
{
    int weishu = 0;
    while (sum)
    {
        sum /= 10;
        weishu++;
    }

    return weishu;
}

bool Not76(long long sum)
{
    while (sum)
    {
        if (sum % 10 == 6)
        {
            if (sum % 100 == 76)
            {
                return false;
            }
            sum /= 10;
        }
        else
        {
            sum /= 10;
        }
    }

    return true;
}

int main(void)
{
    ios::sync_with_stdio;
    cin.tie(0);

    int n = 0;
    cin >> n;

    if (n <= 2)
    {
        cout << "No" << '\n';
        return 0;
    }

    // 判断位数，符合再检测子段
    long long num = 1;
    long long sum = 0;
    while (1)
    {
        sum = num * 76;
        // cout << num << ": " << sum << '\n';
        int weishu = WeiShu(sum);
        if (weishu < n)
        {
            num++;
        }
        else if (weishu == n)
        {
            if (Not76(sum))
            {
                cout << "Yes" << '\n' << sum << '\n';
                return 0;
            }
            else
            {
                num++;
            }
        }
        else
        {
            cout << "No" << '\n';
            return 0;
        }
    }
}