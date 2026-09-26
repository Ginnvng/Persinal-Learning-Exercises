#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<char> arr;
    while(n > 0)
    {
        long long num = 0;
        num = n % 16;
        if(num <= 9)
        {
            arr.insert(arr.begin(),num + '0');
        }
        else
        {
            arr.insert(arr.begin(),'A' + num - 10);
        }
        n /= 16;
    }
    
    //用数组长度作循环次数，输出结果
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout << arr[i];
    }

    // 定义P遍历数组arr，输出结果
    // for(char p : arr)
    // {
    //     cout << p;
    // }

    //这是从张兴泷学长那学来的，更是惊为天人，思路打开了，arr.end()指向数组最后一位元素的下一位，所以 arr.end()-1 为数组元素的最后一位，用指针i来倒序输出结果
    // for(auto i=arr.end()-1;i>=arr.begin();i--)
    // {
    //     cout<<*i;
    // }

    return 0;
}