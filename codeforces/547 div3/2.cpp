#include <iostream>
using namespace std;
#define INF 999999999
int n, a[200000];

int solve()
{
    int init, end, mid, idx, curCount;
    idx = 0;
    init = end = mid = 0;
    while (a[idx++] == 1)
        init++;
    idx = n - 1;
    while (a[idx--] == 1)
        end++;
    idx = 0;
    curCount = 0;
    while (idx != n)
    {
        if (a[idx] == 1)
            curCount++;
        else
        {
            if (curCount > mid)
                mid = curCount;
            curCount = 0;
        }
        idx++;
    }
    if (curCount > mid)
        mid = curCount;
    if (a[n - 1] == 1 && a[0] == 1)
        return max(init + end, mid);
    return mid;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve() << endl;
}