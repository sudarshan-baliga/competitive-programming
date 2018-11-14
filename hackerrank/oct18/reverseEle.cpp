#include <iostream>
#include <limits.h>
using namespace std;

typedef long long ll;
int n, q, l, r, a[100001];

ll subSum(int  l, int r)
{
    ll maxTillNow = LONG_MIN, currSum = 0;
    bool reverse = false;
    int i = 1;
    while (i <= n)
    {
        if (i == l && reverse == false)
        {
            i = r;
            reverse = true;
        }
        currSum += a[i];
        if (currSum < 0)
            currSum = 0;
        else if (currSum > maxTillNow)

            maxTillNow = currSum;
        if (i == l)
        {
            reverse = false;
            i = r;
        }
        if (reverse == true)
            i--;
        else
            i++;
    }
    return maxTillNow;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        cout << subSum(l, r) << endl;
    }
}