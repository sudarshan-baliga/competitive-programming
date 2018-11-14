#include <iostream>
#include <algorithm>
using namespace std;

int t, n, previ[100001], a[100001];
bool flag;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        flag = false;
        for (int j = 1; j <= n; j++)
            cin >> a[j];
        for (int j = 1; j <= n; j++)
        {
            if (previ[a[a[j]]] != a[j] && previ[a[a[j]]] != 0)
            {
                // cout << previ[a[a[j]]] << "|" << a[j] << endl;
                flag = true;
                break;
            }
            previ[a[a[j]]] = a[j];
        }
        if (flag)
            cout
                << "Truly Happy" << endl;
        else
            cout << "Poor Chef" << endl;
        fill(previ, previ + n + 1, 0);
    }
}