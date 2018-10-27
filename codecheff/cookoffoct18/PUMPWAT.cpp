#include <iostream>
#include <algorithm>
using namespace std;
int n, h[100001], t, ans;
int solve(int l, int u)
{
    int index = max_element(h + l, h + u + 1) - h;
    if (index == l || index == u)
        return 1;
    return 1 + min(solve(l, index - 1), solve(index + 1, u));
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
            cin >> h[j];
        ans = solve(1, n);
        cout << ans << endl;
    }
}