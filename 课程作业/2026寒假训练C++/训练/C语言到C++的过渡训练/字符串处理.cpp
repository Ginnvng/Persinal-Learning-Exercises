#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/* 这些都是练习
int main()
{
    string s = "congratulation";
    size_t len1 = s.length();
    size_t len2 = s.size();
    cout << "字符串长度：" << "\n" << "length = "<< len1 << "\n" << "size = " << len2 << endl;
    size_t L1 = 3;
    int pos = 3;
    string s1 = s.substr(pos,L1);
    cout << s1 << "\n";
    int L2 = s.find_last_of("a");
    s1 = s.substr(L2,3);
    cout << s1 << "\n";
}
*/
int main()
{
    string s;
    getline(cin,s);
    string pattern;
    getline(cin,pattern);
    int start,len;
    cin >> start >> len;
    cin.ignore();
    string prefix;
    getline(cin,prefix);
    //原字符串长度
    cout << s.size() << endl;
    //反转后的字符串
    string reversed = s;
    reverse(reversed.begin(),reversed.end());
    cout << reversed << endl;
    //子串第一次出现的位置（-1 表示未找到）
    size_t findlen = s.find(pattern);
    if(findlen == string::npos)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << findlen << endl;
    }
    
    //替换空格后的字符串
    string f = s;
    for(int i = 0; (size_t)i < f.size() ; i++)
    {
        findlen = f.find(" ");
        if(findlen != string::npos)
        {
            f.replace(findlen,1,"_");
        }
        else
        {
            break;
        }
    }
    cout << f << endl;
    //提取的子串
    cout << s.substr(start,len) << endl;

    //是否以指定前缀开始
    if(prefix.empty() || s.substr(0,prefix.length()) == prefix)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}