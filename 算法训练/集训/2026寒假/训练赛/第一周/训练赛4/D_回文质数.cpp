#include <iostream>
#include <cmath>
using namespace std;

bool isPalindromie(long long n);
bool isPrime(long long n);

int main()
{
    int a,b;
    cin >> a >> b;
    for(long long i = a ; i <= b ; i++)
    {
        if(isPalindromie(i))
        {
            if(isPrime(i))
            {
                cout << i << endl;
            }
        }
        
    }
    return 0;
}

bool isPalindromie(long long n)
{   
        // int a = n,b = 0;
        // while(a > 0)
        // {
        //     a /= 10;
        //     b++;
        // }
        // a = n;
        // int sum = 0;
        // while(a > 0)
        // {
        //     sum += a % 10 * pow(10,b-1);
        //     a /= 10;
        //     b--;
        // }
        // if(sum == n) return true;
        // else return false;
        long long ori = n;
        long long rev = 0;
        while(n > 0)
        {
            rev = rev *10 + n % 10;
            n /= 10;
        }
        return rev == ori;
}

bool isPrime(long long n)
{
    // for(int i = 2 ; i < n/2 ; i++)
    // {
    //     if(n % i == 0)
    //     {
    //         return false;
    //     }
    // }
    // return true;
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3 ; i*i <= n ; i += 2)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}