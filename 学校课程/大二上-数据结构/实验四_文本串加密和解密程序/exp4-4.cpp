#include "SqString.cpp"
#include <iostream>
using namespace std;

int main(void)
{
    SqString cstr;
    StrAssign(cstr, "abcdefghijklmnopqrstuvwxyz");
    SqString mstr;
    StrAssign(mstr, "ngzqtcobmuhelkpdawxfyivrsj");
    SqString str;
    // 输入字符后，按照数字来
    string s;
    cin >> s;
    StrAssign(str, s);
}