#include "SqString.cpp"
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    SqString cstr;
    StrAssign(cstr, "abcdefghijklmnopqrstuvwxyz");
    SqString mstr;
    StrAssign(mstr, "ngzqtcobmuhelkpdawxfyivrsj");
    // 输入字符后，通过修改字符数字来进行加密或解密，比如原字符 = mstr[字符-a]
    SqString str;
    string s;
    // cin.ignore();  //只有前面有 cin 的时候才需要它
    getline(cin, s);
    StrAssign(str, s); // 将新字符串录入串
    // 遍历新串，将每个字符加密
    for (int i = 0; i < str.length; i++)
    {
        if (islower(str.data[i]))
            str.data[i] = mstr.data[str.data[i] - 'a'];
    }
    // 输出加密后的字符串
    cout << "加密后的串：";
    DispStr(str);
    // 遍历加密后的串，将每个字符解密

    /* //此解太暴力
    // 先写普通的循环解密
    for (int i = 0; i < str.length; i++)
    {
        // 内层循环，通过遍历，寻找每一位 加密后的串 与 密文 所对应的下标
        for (int j = 0; j < mstr.length; j++)
        {
            if (str.data[i] == mstr.data[j])
            {
                // 找到下标后，通过下标将密文恢复为明文
                str.data[i] = cstr.data[j];
                break;
            }
        }
    }
    */

    /* //此解不是最优解
        // 进阶的解：用map，记录每个密文所对应的下标
        map<char, int> 密文对下标;
        // 遍历一遍密文串，记录每个密文的下标
        for (int i = 0; i < mstr.length; i++)
        {
            密文对下标[mstr.data[i]] = i;
        }
        // 遍历一遍加密的串，解密
        for (int i = 0; i < str.length; i++)
        {
            str.data[i] = cstr.data[密文对下标[str.data[i]]];
        }
    */

    // 最终解：新建数组
    char c[26];
    // 遍历一遍密文串，密文-a为下标，记录明文位置
    for (int i = 0; i < mstr.length; i++)
    {
        c[mstr.data[i] - 'a'] = cstr.data[i];
    }
    // 解密
    for (int i = 0; i < str.length; i++)
    {
        if (islower(str.data[i]))
            str.data[i] = c[str.data[i] - 'a'];
    }
    // 输出解密后的串
    cout << "解密后的串：";
    DispStr(str);
}