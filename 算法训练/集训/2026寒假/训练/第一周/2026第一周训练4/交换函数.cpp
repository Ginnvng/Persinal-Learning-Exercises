#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp;
    temp = y;
    y = x;
    x = temp;
}

int main()
{
    int x, y;
    cin >> x >> y;
    swap(x, y);
    cout << x << " " << y;
}