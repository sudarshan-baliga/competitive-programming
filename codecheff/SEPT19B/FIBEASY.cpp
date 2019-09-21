#include <iostream>
#include <map>
#include <math.h>
#define MAX 60
#define FAST ios_base::sync_with_stdio(false);\
    cin.tie(NULL);
using namespace std;

int fib[MAX];

void findFib()
{
    long long temp, n = MAX, cur;
    fib[0] = 0;
    fib[1] = 1;
    cur = 2;
    while(cur < n)
    {
        fib[cur] += fib[cur - 1] + fib[cur - 2];
        fib[cur] %= 10;
        cur++;
    }
}

long long findMulti(long long n)
{
    long long x = 1, y = 1;
    while( x <= n)
    {
        y = x;
        x *= 2;
    }
    return y;
}

int main()
{
    FAST;
    long long t, n, p, idx;
    findFib();
    cin >> t;
    while(t--)
    {
        cin >> n;
        // p = log2(n);
        // cout << p << endl;
        // cout << pow(2, p) << endl;
        idx = findMulti(n) - 1;
        cout << fib[idx % 60]  << endl;
    }
}