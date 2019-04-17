#include <iostream>
using namespace std;

int main()
{
    long long n, t, count, idx, ans;
    string s;
    char ch;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> s >> ch;
        count = idx = ans = 0;
        while(idx < n)
        {
            if(s[idx] == ch)
            {
                count++;
                // cout << idx << " " << count << endl;
                ans += count * (n - idx);
                idx++;
                count = 0;
                continue;
            }
            count++;
            idx++;
        }
        cout << ans << endl;
    }
}