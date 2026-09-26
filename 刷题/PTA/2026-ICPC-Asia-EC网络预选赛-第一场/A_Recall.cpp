#include <bits/stdc++.h>
using namespace std;

bool find(stack<long long> S, long long num)
{
    set<long long> T;
    while (!S.empty())
    {
        T.insert(S.top());
        S.pop();
    }

    if (T.find(num) != T.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        stack<long long> S;
        char s;
        long long num;

        while (n--)
        {

            cin >> s >> num;

            switch (s)
            {
                case '+':
                    if (S.empty())
                    {
                        S.push(num);
                        cout << '+';
                    }
                    else if (find(S, num))
                    {
                        while (S.top() != num)
                        {
                            S.pop();
                            cout << '-';
                        }
                        // while (!S.empty())
                        // {
                        //     S.pop();
                        //     cout << '-';
                        // }
                        S.pop();
                        S.push(num);
                        cout << '+';
                    }
                    else
                    {
                        S.push(num);
                        cout << '+';
                    }

                    break;
                case 'T':
                    cout << '?';
                    break;
                case 'F':
                    if (find(S, num))
                    {
                        while (S.top() != num)
                        {
                            S.pop();
                            cout << '-';
                        }
                        S.pop();
                        cout << '-';
                        cout << '?';
                    }
                    else
                    {
                        cout << '?';
                    }
                    break;
            }
        }

        while (!S.empty())
        {
            S.pop();
            cout << '-';
        }

        cout << '\n';
    }
}