#include <iostream>
#include <string>
#include <limits>
using namespace std;

string current_text;

int main()
{
    
    size_t pos;
    string new_s;
    int user_do;
    string find_s;
    size_t len;
    while(true)
    {
        cout << "=================简要文本编辑器================="<< endl;
        cout <<"1. insert  2. 删除文本  3. 查找子串  4. 替换文本" << endl;
        cout <<"5.查看当前文本  6.退出编辑器"<< endl;
        cin >> user_do;
        if(user_do == 6)
        {
            cout << "退出编辑器，再见" <<endl;
            break;
        }
        switch (user_do)
        {
            case 1:
            {   
                cout << "插入位置：" << endl;
                cin >> pos;
                if(pos <= current_text.size() && (int)pos >= 0 )
                {
                    cout << "插入：" << endl;
                    cin.ignore();
                    getline(cin,new_s);
                    current_text.insert(pos,new_s);
                    break;
                }
                else
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "插入有误" << endl;
                    break;
                }
            }
            case 3:
            {
                cout << "搜索：" << endl;
                cin.ignore();
                getline(cin,find_s);
                pos = current_text.find(find_s);
                if(pos != string::npos)
                {
                    cout << "第 " << pos + 1 << " 个" << endl;
                }
                else
                {
                    cout << "未找到" << endl;
                }
                break;
            }
            case 2:
            {   
                cout << "你要删除的字符范围是？" << endl;
                cin >> pos >> len;
                if( pos < 0 || len+pos > current_text.size())
                {
                    cout << "数值有误" << endl;
                    break;
                }
                current_text.erase(pos, len);
                break;
                
            }
            case 4:
            {
                cout << "选择你要替换的文本："<< endl;
                cin.ignore();
                getline(cin,new_s);
                pos = current_text.find(new_s);
                if(pos == string::npos)
                {
                    cout << "未找到"<< endl;
                    break;
                }
                len = new_s.size();
                cout << "输入新文本："<< endl;
                getline(cin,new_s);
                current_text.replace(pos,len,new_s);
                break;
            }
            case 5:
            {
                cout << "当前文本：" << "\n" << current_text << endl;
                break;
            }
            default:
            {
                cout << "无效选项，请重新输入" << endl;
                break;
            }

        }
    }
    return 0;
}

