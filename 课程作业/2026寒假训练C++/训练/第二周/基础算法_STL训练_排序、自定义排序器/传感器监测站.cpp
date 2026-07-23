#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    struct XY
    {
        int x;
        int y;
    };

    vector<XY> xy(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> xy[i].x >> xy[i].y;
    }

    sort(xy.begin(), xy.end(), [](const auto &a, const auto &b)
         {
        long long X = (1ll*a.x*a.x)+(1ll*a.y*a.y);
        long long Y = (1ll*b.x*b.x)+(1ll*b.y*b.y);
        if(X != Y)
        {
            return X < Y;
        } 
        else if(a.x != b.x)
        {
            return a.x < b.x;
        }
        else
        {
            return a.y < b.y;
        } });

    for (int i = 0; i < n; ++i)
    {
        cout << xy[i].x << " " << xy[i].y << "\n";
    }
}