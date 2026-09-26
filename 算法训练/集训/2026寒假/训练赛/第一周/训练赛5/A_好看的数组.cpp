#include <iostream>
#include <vector>
using namespace std;

void isPretty(vector<int> arr,int i,int n);
vector<int> bubble_sort(vector<int> arr,int n);

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    isPretty(bubble_sort(arr,n),0,n);
}

vector<int> bubble_sort(vector<int> arr,int n)
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n - 1 - i ; j++)
        {   
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}

void isPretty(vector<int> arr,int i,int n)
{   
    if(i == n - 1)
    {
        cout << "YES" << "\n";
    }
    else if(arr[i]+1 == arr[i+1])
    {
        isPretty(arr,i+1,n);
    }
    else if(arr[i]+1 != arr[i+1])
    {
        cout << "NO" << "\n";
    }
}