#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, a[100], req, count, idx, curEle;
    vector<int> ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        req = n / 4;
        count = 0;
        idx = n - 1;
        while (ans.size() != 3 && idx != -1)
        {
            count = 0;
            while (count < req && idx != -1)
            {
                idx--;
                count++;
                while (idx != -1 && a[idx] == a[idx + 1])
                {
                    idx--;
                    count++;
                }
            }
            if (count == req)
            {
                ans.push_back(a[idx + 1]);
            }
            else
                break;
        }
        if (ans.size() == 3)
        {
            for (auto idx = ans.rbegin(); idx != ans.rend(); idx++)
                cout << *idx << " ";
        }
        else
            cout << -1;
        cout << endl;
        ans.clear();
    }
}