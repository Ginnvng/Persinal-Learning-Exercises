// validator.cpp
// 用法: 输入原始记录的操作(n行) + 你程序重建出的答案字符串,
// 检查这个答案是否满足:元素不重复、T/F结果一致、且去掉'-'后顺序与原始记录完全一致
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> ops(n);
    vector<long long> vals(n);
    for (int i = 0; i < n; i++)
        cin >> ops[i] >> vals[i];

    string ans;
    cin >> ans;

    vector<long long> stk;
    set<long long> exist;
    int ptr = 0; // 指向原始记录操作的第几个

    for (char c : ans)
    {
        if (c == '+')
        {
            if (ptr >= n || ops[ptr] != '+')
            {
                cout << "错误:'+'位置和原始记录对不上\n";
                return 1;
            }
            long long x = vals[ptr];
            if (exist.count(x))
            {
                cout << "错误:push了一个已存在的元素 " << x << "\n";
                return 1;
            }
            stk.push_back(x);
            exist.insert(x);
            ptr++;
        }
        else if (c == '-')
        {
            if (stk.empty())
            {
                cout << "错误:对空栈执行了'-'\n";
                return 1;
            }
            exist.erase(stk.back());
            stk.pop_back();
        }
        else if (c == '?')
        {
            if (ptr >= n || (ops[ptr] != 'T' && ops[ptr] != 'F'))
            {
                cout << "错误:'?'位置和原始记录对不上\n";
                return 1;
            }
            long long x = vals[ptr];
            bool actual = exist.count(x);
            bool expected = (ops[ptr] == 'T');
            if (actual != expected)
            {
                cout << "错误:查询 " << x << " 时,记录是 " << ops[ptr]
                     << ",但重建序列实际结果是 " << (actual ? "T" : "F")
                     << "\n";
                return 1;
            }
            ptr++;
        }
        else
        {
            cout << "错误:答案字符串出现非法字符 " << c << "\n";
            return 1;
        }
    }

    if (ptr != n)
    {
        cout << "错误:重建序列没有覆盖完所有原始记录操作\n";
        return 1;
    }
    cout << "合法\n";
    return 0;
}