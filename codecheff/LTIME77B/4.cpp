#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int t, n, q, k, ans;
vector<int> numbers;
int invCount[32][2];

void solve(int bit, vector<int> v)
{
    if (bit == -1 || v.empty())
        return;
    vector<int> v1, v2;
    int z, o;
    z = o = 0;
    for (auto ele : v)
    {
        if (ele & (1 << bit))
        {
            v1.push_back(ele);
            o++;
            invCount[bit][1] += z;
        }
        else
        {
            v2.push_back(ele);
            z++;
            invCount[bit][0] += o;
        }
    }
    solve(bit - 1, v1);
    solve(bit - 1, v2);
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(invCount, 0, sizeof(invCount));
        cin >> n >> q;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            numbers.push_back(temp);
        }
        solve(30, numbers);
        while (q--)
        {
            cin >> k;
            ans = 0;
            for (int bit = 0; bit < 31; bit++)
            {
                if (k & (1 << bit))
                    ans += invCount[bit][1];
                else
                    ans += invCount[bit][0];
            }
            cout << ans << endl;
        }
    }
}