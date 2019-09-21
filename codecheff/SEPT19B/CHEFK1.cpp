#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long t, n, m, ans, maxEdges, factor;
    bool temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        maxEdges = (n * (n + 1)) / 2;
        if (n == 1)
        {
            if (m == 1 || m == 0)
                cout << m << endl;
            else
                cout << -1 << endl;
            continue;
        }

        if(n == 2)
        {
            if(m == 1)
                cout << 1 << endl;
            else if(m == 2 || m == 3)
                cout << 2 << endl;
            else
                cout << -1 << endl;
            continue;
        }
        
        if (m < n - 1 || m > maxEdges || m == 0)
        {
            cout << -1 << endl;
            continue;
        }
        
        //min spanning tree
        m -= n - 1;
        if (m == 0)
        {
            cout << 2 << endl;
            continue;
        }
        //last two nodes loop
        m -= 2;
        if (m <= 0)
        {
            cout << 2 << endl;
            continue;
        }
        //loops in all other nodes + connect last two node
        m -= n - 2 + 1;
        if (m <= 0)
        {
            cout << 3 << endl;
            continue;
        }
        //now we have circular connection
        ans = 3;
        factor = n / 2;
        if (n % 2 == 0)
        {
             ans += ceil((double)m / factor);
        }
       else
        {
            ans += 2 * (m / (factor + factor + 1));
            temp = m % (factor + factor + 1);
            if (temp > factor)
                ans += 2;
            else if (temp != 0)
                ans += 1;
        }
        cout << ans << endl;
    }
}