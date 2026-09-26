#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (char &c : S)
    {
        int num = (c - 'A' + n) % 26;
        c = num + 'A';
    }
    cout << S << endl;
}