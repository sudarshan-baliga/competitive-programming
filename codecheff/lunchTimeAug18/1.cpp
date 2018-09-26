#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, coins[100000], diff;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        diff = INT_MAX;
        for (int j = 0; j < n; j++)
            cin >> coins[j];
        sort(coins, coins + n);
        for (int j = 0; j < n - 1; j++)
        {
            diff = min(diff, abs(coins[j] - coins[j + 1]));
        }
        cout << diff << endl;
    }
}