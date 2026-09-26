#include <string>
#include <iostream>
using namespace std;

int main()
{
    string W, T;
    cin >> W;
    cin.ignore();
    getline(cin, T);
    int count = 0;

    while (true)
    {
        size_t pos = T.find(W);
        int Wpos = W.size();

        if (pos != string::npos)
        {
            T.replace(pos, Wpos, "***");
            count++;
        }
        else
        {
            break;
        }
    }

    cout << T << "\n" << count << endl;
}