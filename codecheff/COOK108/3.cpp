#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long rem;

long long findBestMoves(long long x, long long cnt)
{
    if (x <= 1)
        return cnt;
    rem = x * x + 1;
    return findBestMoves(ceil(sqrt(rem)), cnt + 1);
}

int main()
{
    int t, x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        cout << findBestMoves(x, 0) << endl;
    }
}