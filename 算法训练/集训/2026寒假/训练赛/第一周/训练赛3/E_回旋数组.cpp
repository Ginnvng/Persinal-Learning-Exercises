#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n , m ;
    cin >> n >> m;
    vector<vector<int>>arr(n,vector<int>(m));//二维vector

    int left = 0;
    int right = m-1;
    int up = 0;
    int down = n-1;
    int number = 1;

    while(number <= n*m)
    {
        for(int i = left ; i <= right && number <= n*m ; i++)
        {
            arr[up][i] = number++;
        }
        up++;

        for(int i = up ; i <= down && number <= n*m ; i++)
        {
            arr[i][right] = number++;
        }
        right--;

        for(int i = right ; i >= left && number <= n*m ; i--)
        {
            arr[down][i] = number++;
        }
        down--;

        for(int i = down ; i >= up && number <= n*m ; i--)
        {
            arr[i][left] = number++;
        }
        left++;
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            cout << arr[i][j] << " " ;
        }
        cout << '\n';
    }

    return 0 ;
}