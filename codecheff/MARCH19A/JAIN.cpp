#include <iostream>
using namespace std;

int t, n, frequency[32];
string d;

//converts every dish to an integer between 0 to 31
void addDish()
{
    bool a, e, I, o, u;
    int idx = 0, len;
    a = e = I = o = u = false;
    len = d.length();
    for (int i = 0; i != len; i++)
    {
        if (d[i] == 'a')
            a = true;
        else if (d[i] == 'e')
            e = true;
        else if (d[i] == 'i')
            I = true;
        else if (d[i] == 'o')
            o = true;
        else if (d[i] == 'u')
            u = true;
    }
    // cout << a << " " << e << " " << I << " " << o << " " << u << " " << endl;
    if (a)
        idx += 1;
    if (e)
        idx += 2;
    if (I)
        idx += 4;
    if (o)
        idx += 8;
    if (u)
        idx += 16;
    frequency[idx]++;
    // cout << d << " " << idx << endl;
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < 31; i++)
        for (int j = i + 1; j < 31; j++)
        {
            if( (i | j) == 31)
                ans += frequency[i] * frequency[j];
        }
    cout << ans << endl;
    
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> d;
            addDish();
        }
        solve();
    }
}