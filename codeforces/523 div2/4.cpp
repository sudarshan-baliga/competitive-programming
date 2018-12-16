#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
const int P = 1e9 + 7;
int n, x, y;
ll ans, j;

struct node
{
    int l, r;
    bool operator<(node &a)
    {
        return l < a.l;
    }
} a[N];
priority_queue<int> q;
priority_queue<int, vector<int>, greater<int>> p;

int main()
{
    cin >> n >> x >> y;
    for(int i = 1; i <= n ; i++)
    {
         cin >> a[i].l >> a[i].r; 
         ans += 1ll * y * (a[i].r - a[i].l);
         ans %= P;
    }
    sort(a, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        while(!p.empty() && p.top() < a[i].l) q.push(p.top()), p.pop();
        if(q.empty()) ans += x;
        else {
            j = q.top();
            if(x <= 1ll * y * (a[i].l - j)) ans += x;
            else ans += 1ll * y * (a[i].l - j), q.pop();
        }
        p.push(a[i].r);
        ans %= P;
    }
    cout << ans << endl;
}   