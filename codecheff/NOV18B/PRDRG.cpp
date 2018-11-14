#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x, y;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if (n == 1)
            cout << 1 << " " << 2 << " ";
        else if (n == 2)
            cout << 1 << " " << 4 << " ";
        else
        {
            x = 1;
            y = 4;
            for (int j = 1; j <= n - 2; j++)
            {
                if (j % 2)
                {
                    x = 2 * x + 1;
                    y = 2 * y;
                }
                else
                {
                    x = 2 * x - 1;
                    y = 2 * y;
                }
            }
            cout << x << " " << y << " ";
        }
    }
}