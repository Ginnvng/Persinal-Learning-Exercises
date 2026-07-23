#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n ;
    vector<int> zhuzi(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> zhuzi[i];
    }
    int high_num = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(zhuzi[i] > zhuzi[i-1] && zhuzi[i] > zhuzi [i+1] && i-1 != -1 && i+1 != n)
        {
            high_num++;
        }
    }
    
   cout << high_num ; 
    return 0;
}