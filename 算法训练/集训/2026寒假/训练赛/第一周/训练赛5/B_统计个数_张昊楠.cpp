#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    cout<<s[0];
    int ss=1;
    for(int i=1;i<n;i++)
    {
        
        if(s[i]==s[i-1])
        {
            ss++;

        }
        else
        {
            cout<<" "<<ss<<endl;
            cout<<s[i];
            ss=1;
        }
    }
    cout << " " << ss << endl;


    return 0;
}