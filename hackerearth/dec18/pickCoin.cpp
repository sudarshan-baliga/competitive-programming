#include <iostream>
#include <math.h>
typedef long long ll;
typedef long double ld;
using namespace std;
 
ld findLog(ld n, ld k)
{
    return log(n) / log(k);
}
 
int main()
{
    long long t, n, k, temp, maxIter, nextIter;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        if(k == 1)
        {
            if(n % 2)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
            continue;
        }
        temp = k + (n / 2) * (k - 1);
        maxIter = floor(findLog(temp, k) - 1);
        temp = 2 * (pow(k, maxIter + 1) - k);
        temp /= k - 1;
        n -= temp;
        nextIter = pow(k, maxIter + 1);
        // cout << nextIter << endl;
        if ( nextIter <= n)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
}