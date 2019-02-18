#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, lr[100000][2], cakes[100002], l, r, cumulativeK[100002], cumulativeKPlusOne[100002], toatlKCakes, minRemoval, removal, addition, totalRemoval, limit;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        limit = -1;
        for (int j = 0; j < n; j++)
        {
            cin >> l >> r;
            cakes[l] += 1;
            cakes[r + 1] -= 1;
            lr[j][0] = l;
            lr[j][1] = r;
            if(r > limit)
                limit = r;
        }
        // get the actual cakes height
        cakes[0] = cumulativeK[0] = cumulativeKPlusOne[0] = toatlKCakes = 0;
        for (int j = 1; j <= limit; j++)
        {
            cakes[j] += cakes[j - 1];
            // cout << cakes[j] << " ";
            if (cakes[j] == k)
            {
                cumulativeK[j] = cumulativeK[j - 1] + 1;
                toatlKCakes += 1;
            }
            else
                cumulativeK[j] = cumulativeK[j - 1];

            if (cakes[j] == k + 1)
                cumulativeKPlusOne[j] = cumulativeKPlusOne[j - 1] + 1;
            else
                cumulativeKPlusOne[j] = cumulativeKPlusOne[j - 1];
            // if (j < 11)
            //     cout << cakes[j] << " ";
        }
        // cout << endl;
        // get the best range to remove
        minRemoval = 1000000;
        for (int j = 0; j < n; j++)
        {
            removal = cumulativeK[lr[j][1]] - cumulativeK[lr[j][0] - 1];
            addition = cumulativeKPlusOne[lr[j][1]] - cumulativeKPlusOne[lr[j][0] - 1];
            totalRemoval = removal - addition;
            if (totalRemoval < minRemoval)
                minRemoval = totalRemoval;
            // cout << removal << " " << addition << endl;
        }
        cout << toatlKCakes - minRemoval << endl;
        fill_n(cakes, limit + 2, 0);
    }
}