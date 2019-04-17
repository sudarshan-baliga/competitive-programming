#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n, m, k, r, c, ans;
    map<pair<int, int>, int> grid;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> m >> k;
        ans =  0;
        grid.clear();
        for(int j = 0; j < k; j++)
        {
            cin >> r >> c;
            if(r != 1 && grid[{r-1, c}])
            {
                ans--;
            }
            else{
                grid[{r, c}] = true;
                ans++;
            }
            if(c  != m  && grid[{r, c + 1}])
            {
                ans--;
            }
            else
            {
                grid[{r,c}] = true;
                ans++;
            }
            if(r != n  && grid[{r + 1, c}])
            {
                ans--;
            }
            else
            {
                grid[{r,c}] = true;
                ans++;
            }
            if(c  != 1 && grid[{r , c - 1}])
            {
                ans--;
            }
            else
            {
                grid[{r,c}] = true;
                ans++;
            }
        }
        cout << ans << endl;
    }
}