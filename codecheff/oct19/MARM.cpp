#include <iostream>
using namespace std;

int main()
{
    long long t, n, a[10000], ans[10000], fixed, extra;
    long long k, temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        fixed = k / n;
        extra = k % n;
       
        if(fixed > 0 && n % 2)
        {
                a[n / 2] = 0;
        }


        if (fixed % 3 != 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                if (fixed % 3 == 1)
                {
                    temp = a[i];
                    a[i] = a[i] ^ a[n - i - 1];
                    a[n - i - 1] = temp;
                }
                else
                {
                    temp = a[n - i - 1];
                    a[n - i - 1] = a[i] ^ a[n - i - 1];
                    a[i] = temp;
                }
            }
        }
        
        if (extra)
        {
            for (int i = 0; i < extra; i++)
                a[i] = a[i] ^ a[n - i - 1];
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}