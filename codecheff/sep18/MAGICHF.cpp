#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x, s, a, b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> x >> s;
        for (int j = 0; j < s; j++)
        {
            cin >> a >> b;
            if (a == x)
                x = b;
            else if (b == x)
                x = a;
        }
        cout << x << endl;
    }
}