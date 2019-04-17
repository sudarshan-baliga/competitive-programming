#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int t, n, x, y, failed;
    set<int> seg[10];
    seg[0] = {};
    seg[1] = {1, 2};
    seg[2] = {0, 1, 3, 4, 6};
    seg[3] = {0, 1, 2, 3, 6};
    seg[4] = {1, 2, 5, 6};
    seg[5] = {0, 2, 3, 5, 6};
    seg[6] = {0, 2, 3, 4, 5, 6};
    seg[7] = {0, 1, 2};
    seg[8] = {0, 1, 2, 3, 4, 5, 6};
    seg[9] = {0, 1, 2, 3, 5, 6};

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        failed = 0;
        cin >> x >> y;
        if (x == 0)
        {
            if (y != 0)
            {
                // cout << "Invalid1" << endl;
                failed = 1;
            }
        }
        else if (seg[x].size() < y)
        {
            failed = 1;
        }
        if (failed)
            cout << "invalid" << endl;
        else
        {
            cout << y << " " << y << endl;
        }
    }
}