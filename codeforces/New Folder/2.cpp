#include <iostream>
using namespace std;

int main()
{
    long long n, ans = 0, a[200001], next = 1000000001;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i > -1; i--)
    {
        if (a[i] < next)
        {
            next = a[i];
            ans += a[i];
        }
        else if (next > 1)
        {
            next--;
            ans += next;
        }
        else
            break;
    }
    cout << ans << endl;
}