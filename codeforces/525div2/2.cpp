#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ll n, k, a[100000], count, j, sub;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    count = j = sub = 0;
    while (j < n && a[j] == 0)
        j++;

    for (; count < k; count++)
    {
        while (j < n && a[j] - sub <= 0)
        {
            j++;
        }
        if (j >= n)
            cout << 0 << endl;
        else
        {
            cout << a[j] - sub<< endl;
            sub += a[j] - sub;
            j++;
        }
    }
}