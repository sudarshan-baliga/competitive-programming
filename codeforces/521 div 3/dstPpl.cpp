#include <iostream>
using namespace std;

int main()
{
    long long n, a[100], ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 1; j < n - 1;)
    {
        if (a[j] == 0 && a[j - 1] == 1 && a[j + 1] == 1)
        {
            ans++;
            a[j+1] = 0;
            j = j + 2;
        }
        else
            j++;
    }
    cout << ans;
}