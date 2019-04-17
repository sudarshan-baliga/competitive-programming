#include <iostream>
using namespace std;

int main()
{
    int n, k, idx = 0, lsc = 0, acount = 0, bcount = 0, ans = 0; //lsc = left most char
    string s;
    cin >> n >> k >> s;
    while (idx < n)
    {
        if (s[idx] == 'a')
            acount++;
        else
            bcount++;
        if (acount <= k || bcount <= k)
            ans++, idx++;
        else
        {
            if (s[lsc] == 'a')
                acount--;
            else
                bcount--;
            lsc++, idx++;
        }
    }
    cout << ans << endl;
} 