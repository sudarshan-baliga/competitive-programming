#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int t, n, ans, a[2001];
bool exists[2001];
bool considered[2001][2001]; //[current index] [last considere index]

double findMedian(multiset<int> x)
{
    auto itr = x.begin();
    int size = x.size();
    advance(itr, size / 2);
    // if (size % 2)
    // {
    //     return *itr;
    // }
    auto itr2 = itr--;
    return (*itr + *itr2) / 2.0;
}

void solve(multiset<int> current, int index, bool available[], int lastIndex)
{
    if (index > n)
        return;
    if (!current.empty() && !considered[index][lastIndex])
    {
        if (current.size() % 2)
        {
            considered[index][lastIndex] = true;
            ans++;
        }
        else
        {
            double median = findMedian(current);
            // cout << "Median in current  iteration " << index << " " << median << endl;
            if (median == floor(median))
            {
                if (available[(int)median])
                {
                    // cout << "yes " << median << endl;
                    considered[index][lastIndex] = true;
                    ans++;
                }
            }
        }
    }
    // do    not consider the index
    solve(current, index + 1, available, lastIndex);
    // consider the index
    current.insert(a[index]);
    available[a[index]] = true;
    solve(current, index + 1, available, lastIndex + 1);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
            cin >> a[j];
        multiset<int> temp;
        n++; //for later stages to do checking
        ans = 0;
        solve(temp, 1, exists, 0);
        cout << ans << endl;
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                considered[j][k] = false;
    }
}
