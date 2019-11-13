#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int stars[1000001];

void updateNextStars(int a)
{
    int root = sqrt(a), x, y;
    for (int i = 1; i <= root; i++)
    {
        if (a % i == 0)
        {
            if (a / i == i)
                stars[i]++;
            else
            {
                stars[i]++;
                stars[a / i]++;
            }
        }
    }
}

int main()
{
    int t, n, a, ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            ans = max(ans, stars[a]);
            updateNextStars(a);
        }
        cout << ans << endl;
        memset(stars, 0, sizeof(int) * 1000001);
    }
}