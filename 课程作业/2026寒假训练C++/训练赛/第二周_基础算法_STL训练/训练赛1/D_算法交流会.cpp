#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> start(N), end(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> start[i] >> end[i];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int length = 0;
    int max_length = 0;
    int j = 0;
    for (int i = 0; i < N && j < N;)
    {
        if (start[i] <= end[j])
        {
            length++;
            max_length = max(max_length, length);
            i++;
        }
        else if (end[j] < start[i])
        {
            length--;
            j++;
        }
    }

    cout << max_length << endl;
}