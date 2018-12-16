#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n, r, g, b, ans = 0;
    long long k;
    cin >> n >> k;
    r = n * 2;
    g = n * 5;
    b = n * 8;
    
    ans += ceil(r / (double) k);
    ans += ceil(g / (double) k);
    ans += ceil(b / (double) k);
    cout << ans;
}