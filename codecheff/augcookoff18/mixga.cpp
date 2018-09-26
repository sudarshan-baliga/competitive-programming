#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, dig, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        ans= 0;
        for (int j = 0; j < n; j++)
        {
            cin >> dig;
            if (i % 2){
                if(abs(ans) >= 0)
                   ans -= dig; 
                else
                    ans += dig;
            }
            else{
                if(abs(ans) > 0)
                    ans += dig; 
                else
                    ans -= dig;
            }
        }
        cout << abs(ans);
        if( abs(ans) >= k)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
}
