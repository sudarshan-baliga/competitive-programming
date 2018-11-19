#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, a, b, k;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> a >> b >> k;
        cout << (k / 2) * (a-b) + (k % 2) * a << endl;
    }
}