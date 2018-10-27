#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

ll dx[8] = {-2, 2, 1, -1, -1, 1, -2, 2};
ll dy[8] = {-1, -1, -2, -2, 2, 2, 1, 1};
ll t, n, x, y;
map<pair<ll, ll>, int> knights;
bool found;
ll check(ll x, ll y)
{
    for (ll i = 0; i < 8; i++)
    {
        if (knights.find(make_pair(x + dx[i], y + dy[i])) != knights.end())
            return 1;
    }
    return 0;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        knights.clear();
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> x >> y;
            knights.insert(make_pair(make_pair(x, y), 1));
        }
        cin >> x >> y;
        bool flag = check(x, y);
        bool flag1 = check(x - 1, y);
        bool flag2 = check(x, y - 1);
        bool flag3 = check(x + 1, y);
        bool flag4 = check(x, y + 1);
        bool flag5 = check(x + 1, y + 1);
        bool flag6 = check(x - 1, y - 1);
        bool flag7 = check(x + 1, y - 1);
        bool flag8 = check(x - 1, y + 1);
        //if not check in the beginning 
        if (flag == 0)
            cout << "NO" << endl;
        //if 
        else if (flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}