#include <iostream>
using namespace std;

int main()
{
    long long t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if( (n / k) % k == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}