#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[100000], maxi = -1, maxi2 = -1, mini = 100001;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (n == 2)
        cout << 0 << endl;
    else
        cout << min(a[n - 2] - a[0], a[n - 1] - a[1]) << endl;
}