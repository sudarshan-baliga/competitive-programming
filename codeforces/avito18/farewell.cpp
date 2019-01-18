#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 100010;
pair<int, int> a[maxn];
int n;
int Ans[maxn], cnt;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].first = n - a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for (int l = 1, r = 0; l <= n; l = r + 1)
    {
        //find numer of clusters (r)
        for (r = l; r < n && a[r + 1].first == a[r].first; ++r)
            ;
        //check if number of clusters is a multiple b
        if ((r - l + 1) % a[l].first)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        //add same color hats for each members of same clusters
        for (int i = l; i <= r; i += a[l].first)
        {
            cnt++;
            for (int j = i; j < i + a[l].first; ++j)
                Ans[a[j].second] = cnt;
        }
    }
    cout << "Possible" << endl;
    for (int i = 1; i <= n; i++)
        cout << Ans[i] << ' ';
    return 0;
}