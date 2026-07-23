#include <iostream>
#include <vector>
using namespace std;

//这道题我没想到怎么用递归……，麻烦讲课时着重讲一下思路，感谢。

void bubble_sort(int len);

vector<int>exist_num;
vector<int>cishu;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
        int down = 0;
        for(int a : exist_num)
        {   
            if(arr[i] == a)
            {
                cishu[down]++;
                break;
            }
            down++;
        }
        if(down == (int)exist_num.size())
            {
                exist_num.push_back(arr[i]);
                cishu.push_back(1);
            }
    }
    int len = exist_num.size();
    bubble_sort(len);
    for(int i = 0 ; i < len ; i++)
    {
        cout << exist_num[i] << " " << cishu[i] << "\n";
    }
    return 0;
}

void bubble_sort(int len)
{
    
    for(int i = 0 ; i < len-1 ; i++)
    {
        for(int j = 0 ; j < len-1-i ; j++)
        {
            if(exist_num[j] > exist_num[j+1])
            {
                swap(exist_num[j],exist_num[j+1]);
                swap(cishu[j],cishu[j+1]);
            }
        }
    }
}
