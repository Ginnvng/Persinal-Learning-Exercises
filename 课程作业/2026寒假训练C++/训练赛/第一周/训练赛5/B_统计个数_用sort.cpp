#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
/***************************************************************************/
//张昊楠思想：
    int count = 1;
    //cout << arr[0]; //先把第一位数打出去
    for(int i = 0 ; i < n ; i++)
    {
        if(i+1 < n && arr[i] == arr[i+1])
        {
            count++; //记录次数
        }
        else
        {
            cout << arr[i] << " " << count << endl;
            count = 1;
        }
    }
    //cout << " " << count<< "\n";
/***************************************************************************/
//游心怡思想：
  
     for(int i = 0 ; i < n ; i++)
    {
        count = 1;
        while (i+1 < n && arr[i]==arr[i+1])
        {
            count++;
            i++;
        }
        cout << arr[i] << " " << count<< "\n";
    }
}
/***************************************************************************/