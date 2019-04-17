#include <iostream>
using namespace std;

int main()
{
    long long n, q, f, k, s[100001];
    cin >> n >> q;
    cin >> f;
    s[0] = 0;
    s[1] = f;
    for (int i = 2; i <= n; i++)
    {
        cin >> f;
        s[i] = s[i - 1] ^ f;
    }
    // for (int i = n + 1; i < 10001; i++)
    //     s[i] = s[i - n - 1];
    // for(int i = 1; i < 10; i++)
    //     cout << s[i] << " ";
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        cout << s[k % (n + 1)] << endl;
    }
}