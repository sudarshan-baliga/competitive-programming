#include <iostream>
#include <vector>
using namespace std;
long long n, a[200000], maxi = 0, secMaxi = 0, total = 0, ans = 0;
bool indexes[200000];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
        if (a[i] > maxi)
        {
            secMaxi = maxi;
            maxi = a[i];
        }
        else if (a[i] > secMaxi)
        {
            secMaxi = a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != maxi)
        {
            if (total - a[i] - maxi == maxi)
            {
                ans++;
                indexes[i] = 1;
            }
        }
        else if (total - a[i] - secMaxi == secMaxi)
        {
            ans++;
            indexes[i] = 1;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n ;i++)
        if(indexes[i] == 1)
            cout << i + 1 << " ";
}