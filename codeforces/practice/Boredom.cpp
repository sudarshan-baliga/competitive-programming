#include <iostream>
#include <algorithm>
using namespace std;

long long n, temp, freq[100001], ans[100001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        freq[temp]++;
    }
    ans[0] = 0;
    ans[1] = freq[1];
    for (int i = 2; i <= 100000; ++i)
    {
        ans[i] = max(freq[i] * i + ans[i - 2], ans[i - 1]);
    }
    cout << ans[100000];
}