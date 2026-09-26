#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i] * pow(-1,i);
    }
    cout << sum ;
    return 0;
}

