#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> s;
    long long a;
    while(cin >> a)
    {
        s.push_back(a);
    }
    long long len = s.size();
    long long sum = 0;
    long long k = (long long)1 << (len -1);
    for(int i = 0 ; i < len ; i++)
    {
        sum += s[i] * k;
    }
    cout << sum;
    return 0;
}

/*
*   这是根据 王新阳同学 的代码学习而来的，给我了很大的启发，原来集合求和有自己的数学规律，
*   所有子集出现的次数是 ： 2 ^ (n - 1)
*   元素总和 * 所有子集出现的次数 = 每个子集的和
*   还有惊为天人的“long long k = (long long)1 << (len -1);”，原来 << 这个符号还能这样用，这个符号代表在二进制中将数左移，也就是 2 ^ 移动的位数。
*/