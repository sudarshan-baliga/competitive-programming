#include <iostream>
using namespace std;
#define MOD 1000000007;
int main()
{
    int n;
    cin >> n;
    // initially ant is at d
    long long zD = 1;
    long long zABC = 0;
    for (int i = 1; i <= n; i++)
    {
        //number of ways of going to a or b or c from d
        long long nzD = zABC * 3 % MOD;
        //from a or b or c to (a or b or c and not the current position)
        long long nzABC = (zABC * 2LL + zD) % MOD;
        zD = nzD;
        zABC = nzABC;
    }
    cout << zD;
}