#include <iostream>
// #define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main()
{
    long long t, a, b, c, req, cur;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        req = a * 1 + b * 2 + c * 3;
        if (req % 2)
        {
            cout << "NO" << endl;
            continue;
        }
        req /= 2;
        
        cur = req / 3;
        // debug(cur)
        if (req != 0 && cur != 0)
        {
            if (c >= cur)
                req -= 3 * cur;
            else
                req -= 3 * c;
        }
        // debug(req)
        cur = req / 2;
        // debug(cur)
        if (req != 0 && cur != 0)
        {
            if (b >= cur)
                req -= 2 * cur;
            else
                req -= 2 * b;
        }

        cur = req;
        if (req != 0 && cur != 0)
        {
            if (a >= cur)
                req -= 1 * cur;
            else
                req -= 1 * a;
        }
        if (req == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}