#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ll n, a[300000], total = 0, m, q, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        total += b;
        a[i] = b;
    }
    sort(a, a + n, greater<int>());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        cout << total - a[b - 1] << endl;
    }
}