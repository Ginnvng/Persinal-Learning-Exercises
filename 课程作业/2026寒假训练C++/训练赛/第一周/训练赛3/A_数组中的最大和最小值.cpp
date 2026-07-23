#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n ;
    vector<int> array(n);

    for(int i = 0;i < n ; i++)
    {
        cin >> array[i];
    }
    
    int max = 0,min = 0;
    min = array[0];
    for(int i = 0 ; i < n ; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
        
        if(array[i] < min)
        {
            min = array[i];
        }
    }
    cout << max << '\n' << min << '\n';
    return 0; 
}
