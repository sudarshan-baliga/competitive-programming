#include <iostream>
#include <algorithm>
using namespace std;
long long t, n, m, h[100001], c[100001], colorCount, maxHeight;
int color[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        for (int j = 1; j <= n; j++)
            cin >> h[j];
        for (int j = 1; j <= n; j++)
            cin >> c[j];
        maxHeight = -1;
        colorCount = 0;
        for (int j = n; j >= 1; j--)
        {
            if (h[j] > maxHeight)
            {
                color[c[j]] = 1;
                maxHeight = h[j];
            }
        }
        for(int j = 1; j <= m; j++)
            colorCount += color[j];
        fill_n(color, m + 1, 0);
        cout << colorCount << endl;
    }
}