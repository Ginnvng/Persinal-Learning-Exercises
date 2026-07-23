#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n ;
    int zimushuliang = 0;
    for(int i = 0;i < n;i++)
    {
        int sum1 = 65;
        int cishu;
        for(int j = 0;j < i+1;j++,zimushuliang++)
        {
            cishu = zimushuliang % 26;
            cout << (char)(sum1 + cishu); 
        }
        cout << '\n';
    }
    return 0;
}
