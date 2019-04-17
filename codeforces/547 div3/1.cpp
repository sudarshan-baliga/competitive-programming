#include <iostream>
using namespace std;
#define INF 999999999
int n, m;

int solve(long long count, long long val)
{
    if (val == m)
        return count;
    long long doub = -1, trip = -1;
    if (val * 2 <= m)
        doub = solve(++count, val * 2);
    if (val * 3 <= m)
        trip = solve(count, val * 3);
    if (doub != -1)
    {
        if (trip != -1)
            return min(doub, trip);
        else
            return doub;
    }
    if (trip != -1)
        return trip;
    else
        return -1;
}

int main()
{

    cin >> n >> m;
    cout << solve(0, n) << endl;
}