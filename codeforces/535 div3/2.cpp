#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[129];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << a[n - 1] << " ";
    for (int i = n - 1; i >= 0; i--)
        if (a[n - 1] % a[i] > 0)
        {
            cout << a[i] << endl;
            exit(0);
        }
    // if x is  div by y
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] == a[i - 1])
        {
            cout << a[i] << endl;
            exit(0);
        }
    }
}